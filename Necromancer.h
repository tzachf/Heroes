//
// Created by zahi on 12/26/18.
//

#ifndef EX5_NECROMANCER_H
#define EX5_NECROMANCER_H

#include "Hero.h"

class Necromancer : public Hero{

public:
    Necromancer(Hero& necromancerToCopy);
    Necromancer(string name, string type, double gold);
    Necromancer(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
                int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed);
    virtual ~Necromancer();
    virtual void specialSkill();
};


#endif //EX5_NECROMANCER_H
