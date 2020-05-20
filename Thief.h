//
// Created by zahi on 12/26/18.
//

#ifndef EX5_THIEF_H
#define EX5_THIEF_H

#include "Hero.h"


class Thief : public Hero{


public:
    virtual ~Thief();
    Thief(Hero& thiefToCopy);
    Thief(string name, string type, double gold);
    Thief(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
    int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed);
    virtual void specialSkill(Hero &hero);
    virtual void specialSkill();
};


#endif //EX5_THIEF_H
