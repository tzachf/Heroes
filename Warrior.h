//
// Created by zahi on 12/26/18.
//

#ifndef EX5_WARRIOR_H
#define EX5_WARRIOR_H


#include "Hero.h"

class Warrior : public Hero{

public:
    virtual ~Warrior();
    Warrior(Hero &warriorToCopy);
    Warrior(string name, string type, double gold);
    Warrior(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
    int numOfWizards, int numOfBlackDragon, bool myTurn, double gold ,bool isAlive,bool specialSkillUsed);
    virtual void specialSkill() ;
    bool getWspecialSkill();
    void setWspecialSkill();
    void setWspecialSkill(bool skill);

};


#endif //EX5_WARRIOR_H
