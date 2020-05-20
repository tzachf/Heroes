//
// Created by zahi on 1/2/19.
//

#ifndef EX5_PLAY_H
#define EX5_PLAY_H


#include "Hero.h"
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"


class Play {
private:
    int numOfplayers;
    int round;
    Hero** heroesList;

public:
    Play();
    Play(int numOfWarrios,int numOfThiefs, int numOfNecros);
    Play(int round,int numOfPlayers, Hero*  heroesList[]);
    ~Play();
    int searchPlayer(string name);
    string getNameByIndex(int index);
    void mixPlayers();
    string getTypeByIndex(int index) const;
    int getNumOfPlayers();
    int getNumOfCreatures(const int index) const;
    int getNumOfZombies(const int index) const;
    int getNumOfVampires(const int index) const;
    int getNumOfBlackDragons(const int index) const;
    int getNumOfWizards(const int index) const;
    int getNumOfArchers(const int index) const;
    double getGoldByIndex(const int index) const;
    bool isTypeExist(string Type,Hero& heroToAttack) const;
    void attack(Hero & attackingHero, Hero& heroToAttack, Creature& attackingCreature, Creature& creatureToAttack);
    Hero & getHeroR(int index);
    Creature &getCreatureR(string Type, int index);
    void startHeroTurn(int index);
    void getDailyGold(int index);
    void buyCreatureForHero(int index, string Type,int amount);
    void getHeroDetails(int index);
    void heroSpecialSkill(int index);
    void heroSpecialSkill(int index, Hero &hero);
    void printArmyByIndex(int index);
    int isThereAWinner();
    void killThisHero(int index);
    bool isAliveByIndex(int index);
    int getNextAliveHero(int index);
    int getRound();
    void saveGame(int heroNum, string path);
    int getNumberOfAlivesHeroes();
    string boolToString(bool boolean);
    bool getWspecialSkillByIndex(int index);
    void setWspecialSkillByIndex(int index);
    bool isMyTurnByIndex(int index);
    bool getSpecialSkillByIndex(int index);
};


#endif //EX5_PLAY_H
