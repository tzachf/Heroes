//
// Created by zahi on 12/29/18.
//

#ifndef EX5_MYEXCEPTIONS_H
#define EX5_MYEXCEPTIONS_H


#include <exception>

class InvalidUserNameException : public std::exception{

public:
    virtual const char* what() const throw();
};


#endif //EX5_MYEXCEPTIONS_H

