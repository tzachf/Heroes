//
// Created by zahi on 12/26/18.
//

#include "Necromancer.h"
#include "Zombie.h"

Necromancer::Necromancer(string name, string type, double gold) : Hero(name, type, gold) {

}

void Necromancer::specialSkill() {
    if(specialSkillUsed==true) {
        numOfcreatures++;
        numOfZombies++;
        creaturesList.push_back(new Zombie(numOfZombies));
        specialSkillUsed= false;
        cout << "Zombie added successfully\n";
    }
}

Necromancer::~Necromancer() {

}

Necromancer::Necromancer(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires,
                         int numOfArchers, int numOfWizards, int numOfBlackDragon, bool myTurn, double gold, bool isAlive, bool specialSkillUsed) : Hero(
        name, type, numOfCreatures, numOfZombies, numOfVampires, numOfArchers, numOfWizards, numOfBlackDragon, myTurn,
        gold,isAlive,specialSkillUsed) {

}

Necromancer::Necromancer(Hero &necromancerToCopy) : Hero(necromancerToCopy){

}
