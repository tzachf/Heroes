//
// Created by zahi on 12/27/18.
//

#include "Zombie.h"

Zombie::Zombie(int amount) : Creature(2, 5 ,50 , amount, "Zombie"){

}



int Zombie::Attack(Creature &creatureToAttack) const {
    int i = 0;
    int leftAttack = this->powerOfAttack;

    if(creatureToAttack.getType() == "Archer") {
        leftAttack = 2*leftAttack;
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
