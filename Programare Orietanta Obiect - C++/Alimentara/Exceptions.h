//
// Created by Lorena on 26.04.2022.
//

#ifndef MAGAZIN_LAB8_9_EXCEPTIONS_H
#define MAGAZIN_LAB8_9_EXCEPTIONS_H
#include <exception>
#include <string>

class MyException: public std::exception{
    std::string error_message;
public:
    MyException(const std::string& error_message):
        error_message(error_message) {}
        std::string getErrorMessage(){return error_message;}

};


#endif //MAGAZIN_LAB8_9_EXCEPTIONS_H
