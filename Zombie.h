//
// Created by zahi on 12/27/18.
//

#ifndef EX5_ZOMBIE_H
#define EX5_ZOMBIE_H


#include "Creature.h"

class Zombie : public Creature{

public:
    Zombie(int amount);
    virtual int Attack(Creature &creatureToAttack) const;
};


#endif //EX5_ZOMBIE_H
