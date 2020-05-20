//
// Created by zahi on 1/3/19.
//

#ifndef EX5_NOTENOUGHMONEY_H
#define EX5_NOTENOUGHMONEY_H


#include "exception"

class NotEnoughmoneyException : public std::exception{

public:
    virtual const char* what() const throw();
};


#endif //EX5_NOTENOUGHMONEY_H
