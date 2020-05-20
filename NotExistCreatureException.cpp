//
// Created by zahi on 1/3/19.
//

#include "NotExistCreatureException.h"
const char *NotExistCreatureException::what() const throw(){
    return "The Creature is not exist in the army\n";
}
