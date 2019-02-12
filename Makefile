CXX = g++
CXXFLAGS = -std=c++11 -g -Wall

THIS_DIR = */Calrissien/src/*

TEST_LINKFLAGS = -lgtest

TEST_DIR = test
SRC_DIR = src

COVERAGE_RESULTS = coverageGCOV = gcov
LCOV = lcov
COVERAGE_RESULTS = results.coverage
COVERAGE_DIR = coverage


SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM = adventureGame
PROGRAM_TEST = testAdventure


.PHONY: all
all: tests compile memory docs static style

# default rule for compiling .cc to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *~ $(SRC_DIR)/*~ $(TEST_DIR)/*~ $(SRC_INCLUDE)/*~ \
	$(SRC_DIR)/*.o $(TEST_SRC)/*.o \
	$(PROGRAM_TEST) $(PROGRAM) \
	docs/code/html docs/code/doxygen.log obj bin \
	*.bak *.temp *.gcov *.gcda *.gcno *.orig ???*/*.orig \
	*.bak ???*/*.bak $(MEMCHECK_RESULTS) $(COVERAGE_DIR) \
	???*/*~ ???*/???*/*~ $(COVERAGE_RESULTS)


compile: $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(INCLUDE) \
	$(SRC_DIR)/*.cpp $(SRC_DIR)/game/*.cpp

tests: $(TEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(SRC_DIR)/*.cpp $(TEST_DIR)/*.cpp $(TEST_LINKFLAGS)
	$(PROGRAM_TEST)

$(PROGRAM): compile
	$(PROGRAM)

$(PROGRAM_TEST): tests
	$(PROGRAM_TEST)

memory: compile
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM)

static: ${SRC_DIR} ${TEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all \
	${TEST_DIR} ${SRC_INCLUDE} ${SRC_DIR} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE} ${SRC_DIR}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/* ${SRC_DIR}

docs: ${SRC_INCLUDE}
	doxygen docs/code/doxyfile

coverage: $(PROGRAM_TEST)
	$(PROGRAM_TEST)
	$(LCOV) --capture --gcov-tool $(GCOV) --directory . --output-file $(COVERAGE_RESULTS)
	$(LCOV) --extract $(COVERAGE_RESULTS) $(THIS_DIR) -o $(COVERAGE_RESULTS)
	genhtml $(COVERAGE_RESULTS) --output-directory $(COVERAGE_DIR)
	rm -f *.gc*
