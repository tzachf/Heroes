//
// Created by zahi on 12/26/18.
//

#include "Warrior.h"

Warrior::Warrior(string name, string type, double gold) : Hero(name, type, gold) {

}

Warrior::~Warrior() {

}

void Warrior::specialSkill()  {
    if(specialSkillUsed) {                              ///change after main
        this->gold += 50;
        if(this->gold > 2500){
            this->gold = 2500;
        }
        specialSkillUsed=false;
        cout << "Gold added successfully\n";
    }
}

bool Warrior::getWspecialSkill() {
    return  specialSkillUsed;
}

void Warrior::setWspecialSkill() {
    specialSkillUsed= true;
}

Warrior::Warrior(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
                 int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed) : Hero(name, type, numOfCreatures,
                                                                                          numOfZombies, numOfVampires,
                                                                                          numOfArchers, numOfWizards,
                                                                                          numOfBlackDragon, myTurn,
                                                                                          gold,isAlive,specialSkillUsed ) {

}

Warrior::Warrior(Hero &warriorToCopy) : Hero(warriorToCopy){

}

void Warrior::setWspecialSkill(bool skill) {
    specialSkillUsed=skill;
}
