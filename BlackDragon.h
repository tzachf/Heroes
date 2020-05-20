//
// Created by zahi on 12/27/18.
//

#ifndef EX5_BLACKDRAGON_H
#define EX5_BLACKDRAGON_H


#include "Creature.h"

class BlackDragon : public Creature{

public:
    BlackDragon(int amount);
    virtual int Attack(Creature &creatureToAttack) const;
};


#endif //EX5_BLACKDRAGON_H
