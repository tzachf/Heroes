//
// Created by zahi on 1/3/19.
//

#include "NotEnoughMoneyException.h"

const char* NotEnoughmoneyException::what() const throw() {
        return "You Dont have enough money\n";

}