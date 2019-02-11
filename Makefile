CXX = g++
CXXFLAGS = -std=c++0x -g -Wall

TEST_LINKFLAGS = -lgtest

TEST_DIR = test
SRC_DIR = src

SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

STATIC_ANALYSIS = cppcheck

STYLE_CHECK = cpplint.py

PROGRAM = adventure
PROGRAM_TEST = testGame


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
	*.bak

compile: $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM) $(INCLUDE) \
	$(SRC_DIR)/*.cpp

#can't name tests because test is a directory
tests: $(TEST_DIR) $(SRC_DIR)
	$(CXX) $(CXXFLAGS) -o $(PROGRAM_TEST) $(INCLUDE) \
	$(SRC_DIR)/[!m]*.cpp $(TEST_DIR)/*.cpp $(TEST_LINKFLAGS)
	$(PROGRAM_TEST)

#need coverage target

memory: compile
	valgrind --tool=memcheck --leak-check=yes $(PROGRAM)

static: ${SRC_DIR} ${TEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all \
	${TEST_DIR} ${SRC_INCLUDE} ${SRC_DIR} --suppress=missingInclude

style: ${TEST_DIR} ${SRC_INCLUDE} ${SRC_DIR}
	${STYLE_CHECK} $(SRC_INCLUDE)/* ${TEST_DIR}/* ${SRC_DIR}

docs: ${SRC_INCLUDE}
	doxygen docs/code/doxyfile
