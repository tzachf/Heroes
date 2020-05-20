//
// Created by zahi on 12/29/18.
//

#include "InvalidUserNameException.h"

const char *InvalidUserNameException::what() const throw(){
    return "invalid name of your hero, please enter name of hero again\n";
}
