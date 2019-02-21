/*
* CPSC 2720 Spring 2019: invalid_parameter_error
* Copyright 2019 Dr. Anvik <john.anvik@uleth.ca>
*
* Adapted for 2720 group project to Spring 2019
* Steven Deutekom <deutekom@uleth.ca>
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

#endif  // INCLUDE_EXCEPTIONS_H_
