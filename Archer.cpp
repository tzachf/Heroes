//
// Created by zahi on 12/27/18.
//

#include "Archer.h"

Archer::Archer(int amount) :Creature(5,4,90, amount , "Archer"){

}
int Archer::Attack(Creature &creatureToAttack) const {
    int i = 0;
    int leftAttack = this->powerOfAttack;

    if(creatureToAttack.getType() == "BlackDragon") {
        leftAttack = leftAttack +1;
    }
    if(creatureToAttack.getPowerOfDefence() > leftAttack){
        return 0;
    }
    else{
        while(creatureToAttack.getPowerOfDefence() <= leftAttack){
            leftAttack = leftAttack - creatureToAttack.getPowerOfDefence();
            i++;

            return i;
        }
    }

    return 0;
}