//
// Created by zahi on 1/2/19.
//

#include <dirent.h>
#include <fstream>
#include <sys/stat.h>
#include "Play.h"
#include <iostream>

Play::Play(int numOfWarriors, int numOfThiefs, int numOfNecros) {
    int i;
    round = 1;
    numOfplayers = numOfNecros + numOfThiefs + numOfWarriors;
    heroesList = new Hero*[numOfNecros + numOfThiefs + numOfWarriors];
    string w;
    string t;
    string n;


    if (numOfWarriors > 0) {
        for (i = 1; i <= numOfWarriors; ++i) {
            cout << "Please insert warrior number " << i << " name:\n";
            cin >> w;
            heroesList[i - 1] = new Warrior(w, "Warrior", 750);
            if (heroesList[i - 1]->getType() == "") {
                delete heroesList[i-1];
		i--;
            }

        }
    }
    if (numOfThiefs > 0) {
        for (i = 1; i <= numOfThiefs; ++i) {
            cout << "Please insert thief number " << i << " name:\n";
            cin >> t;
            heroesList[i + numOfWarriors - 1] = new Thief(t, "Thief", 750);
            if (heroesList[i + numOfWarriors - 1]->getType() == "") {
                delete heroesList[i-1];
		i--;
            }

        }
    }
    if (numOfNecros > 0) {
        for (i = 1; i <= numOfNecros; ++i) {
            cout << "Please insert necromancer number " << i << " name:\n";
            cin >> n;
            heroesList[i + numOfThiefs + numOfWarriors - 1] = new Necromancer(n, "Necromancer", 750);
            if (heroesList[i + numOfThiefs + numOfWarriors - 1]->getType() == "") {
                delete heroesList[i-1];
		i--;
            }

        }
    }mixPlayers();
}


int Play::searchPlayer(string name) {
    for (int k = 0; k < numOfplayers ; ++k) {
        if (heroesList[k]->getName() == name) {
            return k;
        }
    }
    return -1 ;
}


string Play::getNameByIndex(int index) {
    return heroesList[index]->getName();
}


void Play::mixPlayers() {
    for (int j = 0; j < numOfplayers/2; ++j) {
    int r = rand() % numOfplayers;
    Hero* temp = heroesList[j];
    heroesList[j] = heroesList[r];
    heroesList[r] = temp;
    }
}


string Play::getTypeByIndex(int index) const{
    return heroesList[index]->getType();
}
int Play::getNumOfPlayers() {
    return  numOfplayers;
}

int Play::getNumOfCreatures(const int index) const{
    return heroesList[index]->getNumOfCreatures();
}

int Play::getNumOfZombies(const int index) const{
    return heroesList[index]->getNumOfZombies();
}

int Play::getNumOfVampires(const int index) const{
    return heroesList[index]->getNumOfVampires();
}

int Play::getNumOfBlackDragons(const int index) const{
    return heroesList[index]->getNumOfBlackDragons();
}

int Play::getNumOfWizards(const int index) const{
    return heroesList[index]->getNumOfWizards();
}

int Play::getNumOfArchers(const int index) const{
    return heroesList[index]->getNumOfArchers();
}

bool Play::isTypeExist(string Type, Hero &heroToAttack) const {
    if(Type=="Black_Dragon"){
        if(heroToAttack.getNumOfBlackDragons()==0){
            return false;
        }
    }else
    if(Type=="Archer"){
        if(heroToAttack.getNumOfArchers()==0){
            return false;
        }
    }else
    if(Type=="Vampire"){
        if(heroToAttack.getNumOfVampires()==0){
            return false;
        }
    }else
    if(Type=="Wizard"){
        if(heroToAttack.getNumOfWizards()==0){
            return false;
        }
    }else
    if(Type=="Zombie"){
        if(heroToAttack.getNumOfZombies()==0){
            return false;
        }
    }else{
        return false;
    }
    return true;
}
Hero& Play::getHeroR(int index) {
    return *heroesList[index];
}
void Play::attack(Hero &attackingHero, Hero &heroToAttack, Creature &attackingCreature,
                  Creature &creatureToAttack) {
    if((&attackingCreature!=NULL)&&(&heroToAttack!=NULL)&&(&attackingCreature!=NULL)&&(&creatureToAttack!=NULL)) {
        attackingHero.attackOpponent(heroToAttack, creatureToAttack, attackingCreature);
    }
}
Creature & Play::getCreatureR(string Type, int index) {
    return heroesList[index]->getCreaturRefByType(Type);
}
void Play::startHeroTurn(int index) {
    heroesList[index]->startTurn();
}
void Play::getDailyGold(int index) {
    heroesList[index]->getDailyGold();
}
void Play::buyCreatureForHero(int index, string Type, int amount) {
    for (int i = 0; i < amount; ++i) {
        heroesList[index]->buyCreatures(Type);
    }

}
double Play::getGoldByIndex(const int index) const {
    return heroesList[index]->getGold();
}

void Play::getHeroDetails(int index) {
    heroesList[index]->printDetails();
}

void Play::heroSpecialSkill(int index) {
    heroesList[index]->specialSkill();
}

void Play::heroSpecialSkill(int index, Hero &hero) {
    if(&hero!=NULL) {
        heroesList[index]->specialSkill(hero);
    }
}

void Play::printArmyByIndex(int heroNum) {
    cout << getNameByIndex(heroNum) <<" " << getTypeByIndex(heroNum)
         << "\n";
    string myCreatures = "";
    if(getNumOfCreatures(heroNum) > 0) {
        if (getNumOfBlackDragons(heroNum) > 0) {
            myCreatures += to_string(getNumOfBlackDragons(heroNum)) + " Black_Dragon ";
        }
        if (getNumOfWizards(heroNum) > 0) {
            myCreatures += to_string(getNumOfWizards(heroNum)) + " Wizard ";
        }
        if (getNumOfArchers(heroNum) > 0) {
            myCreatures += to_string(getNumOfArchers(heroNum)) + " Archer ";
        }
        if (getNumOfVampires(heroNum) > 0) {
            myCreatures += to_string(getNumOfVampires(heroNum)) + " Vampire ";
        }
        if (getNumOfZombies(heroNum) > 0) {
            myCreatures += to_string(getNumOfZombies(heroNum)) + " Zombie ";
        }
        myCreatures = myCreatures.substr(0, myCreatures.length() - 1);
        cout << myCreatures << ".\n\n";
    }else{
        cout << "\n\n";
    }

}

int Play::isThereAWinner() {
    int count = 0;

    if(getNumberOfAlivesHeroes() > 1){
        return -1;
    }

    for (int i = 0; i < getNumOfPlayers(); ++i) {
        if(heroesList[i]->getNumOfCreatures() > 0 ){
            count++;
        }
    }
    if(count == 1 ){
        for (int i = 0; i < getNumOfPlayers(); ++i) {
            if(heroesList[i]->getNumOfCreatures() > 0 ){
                return  i;
            }
        }
    }
    return  -1;
}

void Play::killThisHero(int index) {
    heroesList[index]->killHero();

}

bool Play::isAliveByIndex(int index) {
    return heroesList[index]->isAlive();
}

int Play::getNextAliveHero(int index) {
    int next = index;
    if(next == numOfplayers-1){
        next = 0;
        round++;
    }else{
        next++;
    }
    while(!isAliveByIndex(next)){
        if(next == numOfplayers-1){
            next = 0;
            round++;
        }else{
            next++;
        }
    }
    return next;
}

int Play::getRound() {
    return round;
}

void Play::saveGame(int heroNum, string path) {
    //char* gameFilePath=NULL ;
    string filePath;
    filePath = string(path);
    int counter=0;
    for(int i = filePath.length()-1;i>0;i--){
        if(filePath[i]!='/'){
            counter++;
        }else{
            break;
        }
    }
    filePath=filePath.substr(0,filePath.length() - counter);
    //filePath="/home/zahi/CLionProjects/ex5/cmake-build-debug/";
    string gFilePath = filePath +"game";
    char* gameFilePath = new char[(gFilePath.length())];
    copy(gFilePath.begin(), gFilePath.end(),gameFilePath);
//    for (int j = 0; j < gFilePath.length(); ++j) {
//        gameFilePath[j]=gFilePath[j];
//    }
    mkdir(gameFilePath,0777);
    delete []gameFilePath;
    string gameDetailsFile = gFilePath + "/Game.txt";
    ofstream gameDetails (gameDetailsFile);

    if(gameDetails.is_open()){
        gameDetails << round << "\n";
        gameDetails << heroNum << "\n";
        gameDetails << getNumOfPlayers() << "\n";
        for(int i=0;i<getNumOfPlayers();i++){
            gameDetails<<getNameByIndex(i)<<"\n";
        }
    }
    gameDetails.close();

    for(int i=0;i<getNumOfPlayers();i++){
        string heroFolder= filePath + getNameByIndex(i);
        char* heroFilePath = new char[heroFolder.length()+1];
        copy(heroFolder.begin(),heroFolder.end(),heroFilePath);
        mkdir(heroFilePath,0777);                                       ///itamar 0777
        delete [] heroFilePath;
        string heroDetailsPath = heroFolder+"/"+getNameByIndex(i)+".txt";
        ofstream heroDetailsFile (heroDetailsPath);
        if(heroDetailsFile.is_open()){

            heroDetailsFile<<getNameByIndex(i)<<"\n";
            heroDetailsFile<<getTypeByIndex(i)<<"\n";
            heroDetailsFile<<getNumOfCreatures(i)<<"\n";
            heroDetailsFile<<getNumOfZombies(i)<<"\n";
            heroDetailsFile<<getNumOfVampires(i)<<"\n";
            heroDetailsFile<<getNumOfArchers(i)<<"\n";
            heroDetailsFile<<getNumOfWizards(i)<<"\n";
            heroDetailsFile<<getNumOfBlackDragons(i)<<"\n";
            heroDetailsFile<<boolToString(isMyTurnByIndex(i))<<"\n";
            heroDetailsFile<<to_string(getGoldByIndex(i))<<"\n";
            heroDetailsFile<<boolToString(isAliveByIndex(i))<<"\n";
            heroDetailsFile<<boolToString(getSpecialSkillByIndex(i))<<"\n";
        }
        heroDetailsFile.close();
    }

}

int Play::getNumberOfAlivesHeroes() {
    int count = 0;
    for (int i = 0; i < numOfplayers; ++i) {
        if(heroesList[i]->isAlive()){
            count++;
        }
    }
    return count;
}

string Play::boolToString(bool boolean) {
    if(boolean){
        return "true";
    }else{
        return "false";
    }
}

bool Play::getWspecialSkillByIndex(int index) {
    return ((Warrior*)heroesList[index])->getWspecialSkill();
}

void Play::setWspecialSkillByIndex(int index) {
    ((Warrior*)heroesList[index])->setWspecialSkill();

}

bool Play::isMyTurnByIndex(int index) {
    return heroesList[index]->isMyTurn();
}

Play::Play(int round, int numOfPlayers, Hero *heroesList1[]) {
    if(heroesList1!=NULL) {
        this->round = round;
        this->numOfplayers = numOfPlayers;
        heroesList = new Hero *[numOfplayers];
        for (int i = 0; i < numOfPlayers; ++i) {
            if (heroesList1[i]->getType() == "Warrior") {
                this->heroesList[i] = new Warrior(*heroesList1[i]);
                ((Warrior *) this->heroesList[i])->setWspecialSkill(((Warrior *) heroesList1[i])->getWspecialSkill());

            } else if (heroesList1[i]->getType() == "Necromancer") {
                this->heroesList[i] = new Necromancer(*heroesList1[i]);

            } else if (heroesList1[i]->getType() == "Thief") {
                this->heroesList[i] = new Thief((*heroesList1[i]));
            }
        }
    }

}


Play::~Play(){
    for (int i = 0; i <numOfplayers; ++i) {
        delete heroesList[i];
    }
    delete  []heroesList;
}

Play::Play() {

}

bool Play::getSpecialSkillByIndex(int index) {
    return heroesList[index]->getSpecialSkill();
}






