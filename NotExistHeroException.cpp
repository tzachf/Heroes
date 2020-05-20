//
// Created by Zahi Kapri on 29/12/2018.
//

#include "NotExistHeroException.h"

const char *NotExistHeroException::what() const throw(){
    return "The hero is not exist in the game\n";
}
