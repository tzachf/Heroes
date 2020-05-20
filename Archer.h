//
// Created by zahi on 12/27/18.
//

#ifndef EX5_ARCHER_H
#define EX5_ARCHER_H


#include "Creature.h"

class Archer : public Creature{

public:
    Archer(int amount);
    int Attack(Creature &creatureToAttack) const;
};


#endif //EX5_ARCHER_H
