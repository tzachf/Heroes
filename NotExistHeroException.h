//
// Created by Zahi Kapri on 29/12/2018.
//

#ifndef EX5_NOTEXISTHEROEXCEPTION_H
#define EX5_NOTEXISTHEROEXCEPTION_H

#include "exception"

class NotExistHeroException : public std::exception{

public:
    virtual const char* what() const throw();
};


#endif //EX5_NOTEXISTHEROEXCEPTION_H
