/**
 * @author Dr. Anvik <john.anvik@uleth.ca>
 * @date 2019 spring
 * @author Steven Deutekom <deutekom@uleth.ca>
 * @author Max Niu <max.niu@uleth.ca>
 * @date 2019 spring
 */
#ifndef CALRISSIEN_2720_EXCEPTIONS_H_
#define CALRISSIEN_2720_EXCEPTIONS_H_

#include <stdexcept>

/**
* Exception for an invalid parameter passed to a constructor or method.
*/
class invalid_parameter_error: public std::runtime_error {
  public:
    /**
    * @param errMessage An error message.
    */
    explicit invalid_parameter_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
* Exception for an invalid input entered by the user.
*/
class invalid_input_error: public std::runtime_error {
  public:
    /**
    * @param errMessage An error message.
    */
    explicit invalid_input_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
* Exception for an invalid record data used with ObjectBlueprints.
*/
class invalid_record_error: public std::runtime_error {
  public:
    /**
    * @param errMessage An error message.
    */
    explicit invalid_record_error(const char* errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
* Exception for when an object is missing a required part.
*/
class unfinished_object_error: public std::runtime_error {
  public:
    /**
    * @param errMessage An error message.
    */
    explicit unfinished_object_error(std::string errMessage) :
        std::runtime_error(errMessage) {
    }
};

/**
* Exception for when a file doesn't open properly.
*/
class my_file_error: public std::runtime_error {
  public:
    /**
    * @param errMessage An error message.
    */
    explicit my_file_error(std::string errMessage) :
        std::runtime_error(errMessage) {
    }
};

#endif  // INCLUDE_EXCEPTIONS_H_
