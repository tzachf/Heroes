//
// Created by zahi on 1/3/19.
//

#ifndef EX5_NOTEXISTCREATUREEXCEPTION_H
#define EX5_NOTEXISTCREATUREEXCEPTION_H
#include "exception"

class NotExistCreatureException : public std::exception{

public:
virtual const char* what() const throw();
};



#endif //EX5_NOTEXISTCREATUREEXCEPTION_H
