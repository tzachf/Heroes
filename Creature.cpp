//
// Created by zahi on 12/26/18.
//

#include "Creature.h"

Creature::Creature(int powerAttack, int powerDefence, int _cost ,int amount, string type) {
    powerOfAttack = powerAttack;
    powerOfDefence = powerDefence;
    this->cost = _cost;
    this->type = type;
    this->amount=amount;
    this->isAlive=true;
}

Creature::~Creature() {

}
string Creature::getType() {
    return this->type;
}

int Creature::Attack(Creature &creatureToAttack) const {
    if(&creatureToAttack!=NULL) {

        int i = 0;
        int leftAttack = this->powerOfAttack;


        if (creatureToAttack.powerOfDefence > leftAttack) {
            return 0;
        } else {
            while (leftAttack >= creatureToAttack.powerOfDefence) {
                leftAttack = leftAttack - creatureToAttack.powerOfDefence;
                i++;

                return i;
            }
        }
    }
    return 0;
}

int Creature::getAmount() {
    return this->amount;
}

int Creature::getPowerOfAttack() {
    return this->powerOfAttack;
}

int Creature::getPowerOfDefence() {
    return this->powerOfDefence;
}
void Creature::getDetails() {
    cout<<"Attack level:"<<powerOfAttack<<", Defense level:"<<powerOfDefence;
}

void Creature::killCreature() {
    isAlive=false;
}

bool Creature::isCreatureAlive() {
    return isAlive;
}

