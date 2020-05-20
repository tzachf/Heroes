//
// Created by zahi on 12/26/18.
//
#include <iostream>
#include <list>

#include "Creature.h"
#include "InvalidUserNameException.h"

#ifndef EX5_HEROES_H
#define EX5_HEROES_H


using namespace std;

class Hero {

protected:
    string heroName;
    string typeOfHero;
    int numOfZombies;
    int numOfVampires;
    int numOfArchers;
    int numOfWizards;
    int numOfBlackDragon;
    int numOfcreatures;
    bool myTurn;
    double gold;
    bool alive;
    bool specialSkillUsed;
    list<Creature*> creaturesList;
public:
    Hero(Hero& heroToCopy);
    Hero(string name,string type,int numOfCreatures,int numOfZombies,int numOfVampires,int numOfArchers, int numOfWizards, int numOfBlackDragon, bool myTurn, double gold,bool isAlive,bool specialSkillUsed);
    Hero(string name, string type, double gold);
    bool checkValidUser(string nameToCheck);
    virtual ~Hero();
    virtual void specialSkill() = 0;
    virtual void specialSkill(Hero &hero);
    bool buyCreatures(string creature);
    void getDailyGold();
    bool attackOpponent(Hero &opponent, Creature &hisCreature , Creature const &myCreature);
    void printDetails()const;
    void startTurn();
    double getGold();
    void setGold(double newAmount);
    void decreaseCreatures(Hero& hero, Creature& creature);
    string getName() const;
    string getType() const;
    int getNumOfCreatures() const;
    int getNumOfZombies() const;
    int getNumOfVampires() const;
    int getNumOfBlackDragons() const;
    int getNumOfWizards() const;
    int getNumOfArchers() const;
    Creature& getCreaturRefByType(string &Type);
    void killHero();
    bool isAlive();
    bool isMyTurn();
    bool getSpecialSkill();



};


#endif //EX5_HEROES_H
