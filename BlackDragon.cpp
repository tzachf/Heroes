//
// Created by zahi on 12/27/18.
//

#include "BlackDragon.h"


BlackDragon::BlackDragon(int amount) : Creature(9,10,200, amount, "Black_Dragon"){

}


int BlackDragon::Attack(Creature &creatureToAttack) const {
    int i = 0;
    int opDefense=0;

    if(creatureToAttack.getType()=="Wizard"){
        opDefense=2*creatureToAttack.getPowerOfDefence();
    }else{
        opDefense=creatureToAttack.getPowerOfDefence();
    }

    int leftAttack = this->powerOfAttack;

    if(creatureToAttack.getPowerOfDefence() > leftAttack){
        return 0;
    }
    while (leftAttack>=opDefense){
        leftAttack=leftAttack-opDefense;
        i++;
    }
    return i;

}