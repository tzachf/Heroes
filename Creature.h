//
// Created by zahi on 12/26/18.
//


#ifndef EX5_CREATURES_H
#define EX5_CREATURES_H

#include <iostream>
using namespace std;

class Creature {
protected:
    int powerOfAttack;
    int powerOfDefence;
    int cost;
    int amount;
    string type;
    bool isAlive;
public:
    Creature(int powerAttack, int powerDefence, int _cost, int amount, string type);
    ~Creature();
    virtual int Attack(Creature &creatureToAttack) const;
    string getType();
    int getPowerOfAttack();
    int getPowerOfDefence();
    int getAmount();
    void getDetails();
    void killCreature();
    bool isCreatureAlive();
};


#endif //EX5_CREATURES_H
