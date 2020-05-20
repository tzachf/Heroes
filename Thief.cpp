//
// Created by zahi on 12/26/18.
//

#include "Thief.h"
#include "NotExistHeroException.h"
#include "Necromancer.h"

Thief::Thief(string name, string type, double gold): Hero(name,type,gold){

}



Thief::~Thief(){

}

void Thief::specialSkill(Hero &hero) {

    if(specialSkillUsed==true) {
        if (hero.getGold() >= 70) {
            hero.setGold(hero.getGold() - 70);
            this->gold += 70;
        } else if (hero.getGold() > 0 && hero.getGold() < 70) {
            hero.setGold(0);
            this->gold += hero.getGold();
        }
        if (this->gold > 2500) {
            this->gold = 2500;
        }
        specialSkillUsed=false;
    }
}
void Thief::specialSkill() {

}

Thief::Thief(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
             int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed) : Hero(name, type, numOfCreatures,
                                                                                      numOfZombies, numOfVampires,
                                                                                      numOfArchers, numOfWizards,
                                                                                      numOfBlackDragon, myTurn, gold,isAlive,specialSkillUsed) {

}

Thief::Thief(Hero &thiefToCopy) : Hero(thiefToCopy){

}
