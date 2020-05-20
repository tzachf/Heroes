//
// Created by zahi on 12/26/18.
//

#include <cstring>
#include "Hero.h"
#include "Vampire.h"
#include "Archer.h"
#include "Zombie.h"
#include "Wizard.h"
#include "BlackDragon.h"


Hero::Hero(string name, string type, double gold) {
    InvalidUserNameException myex;
    try {
        if (checkValidUser(name) == true) {
            heroName = name;
            typeOfHero = type;
            this->gold = 750;
            numOfZombies = 0;
            numOfVampires = 0;
            numOfArchers = 0;
            numOfWizards = 0;
            numOfBlackDragon = 0;
            numOfcreatures = 0;
            myTurn = true;
            alive=true;
            specialSkillUsed=true;
        } else {
            throw myex;
        }
    }
    catch(std::exception &e){
        cout << e.what() << endl;
    }


  ///  list<Creature*> creaturesList;


}


Hero::~Hero() {
    for (list<Creature*>::iterator it = creaturesList.begin(); it != creaturesList.end() ; ++it) {
            delete *it;
    }
    heroName.clear();
    typeOfHero.clear();
}


bool Hero::buyCreatures(string creature)  {
    if (&creature != NULL) {
        if (creature == "Archer") {
            if (gold >= 90) {
                gold = gold - 90;
                numOfcreatures++;
                numOfArchers++;
                creaturesList.push_back(new Archer(numOfArchers));
                return true;
            } else {
                return false;
            }
        } else if (creature == "Zombie") {
            if (gold >= 50) {
                gold = gold - 50;
                numOfcreatures++;
                numOfZombies++;
                creaturesList.push_back(new Zombie(numOfZombies));
                return true;
            } else {
                return false;
            }
        } else if (creature == "BlackDragon") {
            if (gold >= 200) {
                gold = gold - 200;
                numOfcreatures++;
                numOfBlackDragon++;
                creaturesList.push_back(new BlackDragon(numOfBlackDragon));
                return true;
            } else {
                return false;
            }
        } else if (creature == "Vampire") {
            if (gold >= 80) {
                gold = gold - 80;
                numOfcreatures++;
                numOfVampires++;
                creaturesList.push_back(new Vampire(numOfVampires));
                return true;
            } else {
                return false;
            }
        } else if (creature == "Wizard") {
            if (gold >= 150) {
                gold = gold - 150;
                numOfcreatures++;
                numOfWizards++;
                creaturesList.push_back(new Wizard(numOfWizards));
                return true;
            } else {
                return false;
            }
        }
        return true;
    }
}

void Hero::getDailyGold() {
    if(myTurn== true) {
        gold = gold + 100;
        if(this->gold > 2500){
            this->gold = 2500;
        }
        myTurn = false;
    }
}



bool Hero::attackOpponent(Hero &opponent, Creature &hisCreature, Creature const &myCreature) {
    int numOfKills;
    int amount;

    if(&opponent == NULL || &hisCreature == NULL || &myCreature == NULL){
        return false;
    }

    string hisCreatureType = hisCreature.getType();
    for (list<Creature*>::reverse_iterator it = opponent.creaturesList.rbegin(); it != opponent.creaturesList.rend() ; ++it){
            if ((*it)->getType() == hisCreatureType) {
                amount = (*it)->getAmount();
                numOfKills = myCreature.Attack(*(*it));
                break;
            }
    }
    list<Creature*>::reverse_iterator it = opponent.creaturesList.rbegin();
    while(numOfKills != 0 && amount !=0){
        for (it=it; it != opponent.creaturesList.rend() ; ++it) {
                if(((*it)->getType() == hisCreature.getType())&&(*it)->isCreatureAlive()){
                    decreaseCreatures(opponent, hisCreature);
                    (*it)->killCreature();
                    break;
                }
                //it = creaturesList.erase(it)z
        }
        numOfKills--;
        amount--;
    }

    if(opponent.numOfcreatures==0){
        this->gold=this->gold + opponent.gold;
        if(this->gold >2500){
            this->gold = 2500;
        }
    }

    return false;
}

void Hero::printDetails() const{
    cout<< heroName << " " << typeOfHero<< "\n";
    cout<<gold<<" gold\n";
    string details = "";
    if(numOfcreatures>0) {
        if (numOfBlackDragon > 0) {
            details+= to_string(numOfBlackDragon) + " Black_Dragon ";
        }
        if (numOfWizards > 0) {
            details+= to_string(numOfWizards) + " Wizard ";
        }
        if (numOfArchers > 0) {
            details+= to_string(numOfArchers) + " Archer ";
        }
        if (numOfVampires > 0) {
            details+= to_string(numOfVampires) + " Vampire ";
        }
        if (numOfZombies > 0) {
            details+= to_string(numOfZombies) + " Zombie ";
        }
        details = details.substr(0,details.length()-1);
        cout << details << ".\n";
    } else{cout<<"\n";}

}

void Hero::startTurn() {
    myTurn = true;
}

bool Hero::checkValidUser(string nameToCheck) {
    if((nameToCheck.length() > 31)){
        return false;
    }
    for (int i = 0; i < nameToCheck.length(); ++i) {
        if ((nameToCheck[i] < 'a' && nameToCheck[i] > 'Z') || (nameToCheck[i] > '9' && nameToCheck[i] < 'A') ||
            nameToCheck[i] < '0' || nameToCheck[i] > 'z') {
            return false;
        }
    }
    return true;
}

double Hero::getGold() {
    return gold;
}

void Hero::setGold(double newAmount) {
    this->gold = newAmount;

}

void Hero::decreaseCreatures(Hero &hero, Creature &creature) {
    if(creature.getType() == "Zombie"){
        hero.numOfZombies--;
        hero.numOfcreatures--;
    }
    else if(creature.getType() == "BlackDragon"){
        hero.numOfBlackDragon--;
        hero.numOfcreatures--;
    }
    else if(creature.getType() == "Archer"){
        hero.numOfArchers--;
        hero.numOfcreatures--;
    }
    else if(creature.getType() == "Wizard"){
        hero.numOfWizards--;
        hero.numOfcreatures--;
    }
    else if(creature.getType() == "Vampire"){
        hero.numOfVampires--;
        hero.numOfcreatures--;
    }
}

string Hero::getName() const{
    return this->heroName;
}

string Hero::getType() const{
    return  this->typeOfHero;
}

int Hero::getNumOfCreatures() const{
    return this->numOfcreatures;
}

int Hero::getNumOfZombies() const{
    return this->numOfZombies;
}

int Hero::getNumOfVampires() const{
    return this->numOfVampires;
}

int Hero::getNumOfBlackDragons() const{
    return this->numOfBlackDragon;
}

int Hero::getNumOfWizards() const{
    return numOfWizards;
}

int Hero::getNumOfArchers() const{
    return numOfArchers;
}
Creature& Hero::getCreaturRefByType(string &Type) {
    if (&Type != NULL) {
        list<Creature *>::iterator zaza = this->creaturesList.end();
        for (list<Creature *>::reverse_iterator revIt = creaturesList.rbegin();
             revIt != creaturesList.rend(); revIt++) {
            //Creature* creatureToSearch = *it;

            if (Type == (*revIt)->getType()) {
                return *(*revIt);     //////*creatureToSearch;
            }


        }
    }
}

void Hero::specialSkill(Hero &hero) {

}

void Hero::killHero() {
    alive=false;

}

bool Hero::isAlive() {
    return alive;
}

bool Hero::isMyTurn() {
    return myTurn;
}


Hero::Hero(string name, string type, int numOfCreatures, int numOfZombies, int numOfVampires, int numOfArchers,
           int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed) {
    this->heroName=name;
    this->typeOfHero=type;
    this->numOfcreatures=numOfCreatures;
    this->numOfZombies=numOfZombies;
    this->numOfVampires=numOfVampires;
    this->numOfArchers=numOfArchers;
    this->numOfBlackDragon=numOfBlackDragon;
    this->numOfWizards=numOfWizards;
    this->myTurn=myTurn;
    this->gold=gold;
    this->alive=isAlive;
    this->specialSkillUsed=specialSkillUsed;
    for(int i=0;i<numOfZombies;i++){
        creaturesList.push_back(new Zombie(i));
    }
    for(int i=0;i<numOfVampires;i++){
        creaturesList.push_back(new Vampire(i));
    }
    for(int i=0;i<numOfArchers;i++){
        creaturesList.push_back(new Archer(i));
    }
    for(int i=0;i<numOfWizards;i++){
        creaturesList.push_back(new Wizard(i));
    }
    for(int i=0;i<numOfBlackDragon;i++){
        creaturesList.push_back(new BlackDragon(i));
    }
}

Hero::Hero(Hero &heroToCopy) {
    if(&heroToCopy != NULL) {
        heroName = heroToCopy.heroName;
        typeOfHero = heroToCopy.typeOfHero;
        this->gold = heroToCopy.gold;
        numOfZombies = heroToCopy.numOfZombies;
        numOfVampires = heroToCopy.numOfVampires;
        numOfArchers = heroToCopy.numOfArchers;
        numOfWizards = heroToCopy.numOfWizards;
        numOfBlackDragon = heroToCopy.numOfBlackDragon;
        numOfcreatures = heroToCopy.numOfcreatures;
        myTurn = heroToCopy.myTurn;
        alive = heroToCopy.alive;
        specialSkillUsed=heroToCopy.specialSkillUsed;
        for (int i = 0; i < numOfZombies; i++) {
            creaturesList.push_back(new Zombie(i));
        }
        for (int i = 0; i < numOfVampires; i++) {
            creaturesList.push_back(new Vampire(i));
        }
        for (int i = 0; i < numOfArchers; i++) {
            creaturesList.push_back(new Archer(i));
        }
        for (int i = 0; i < numOfWizards; i++) {
            creaturesList.push_back(new Wizard(i));
        }
        for (int i = 0; i < numOfBlackDragon; i++) {
            creaturesList.push_back(new BlackDragon(i));
        }
    }
}

bool Hero::getSpecialSkill() {
    return specialSkillUsed;
}




