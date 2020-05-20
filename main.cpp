#include <iostream>
#include "Warrior.h"
#include "Thief.h"
#include "Necromancer.h"
#include "NotExistHeroException.h"
#include "Play.h"
#include "NotExistCreatureException.h"
#include "NotEnoughMoneyException.h"
#include <fstream>

using  namespace std;

///dont write if dead

int main(int argc, char* argv[]) {
    string pathS (argv[0]);
    Play *game ;
    int heroNum = 0;
    if (argc == 5) {                           /// if argc == 5


        int numOfWarriors = atoi(argv[2]);
        int numOfThiefs = atoi(argv[3]);
        int numOfNecros = atoi(argv[4]);
        int i;
        heroNum = 0;
        game = new Play(numOfWarriors, numOfThiefs, numOfNecros);
    } else if (argc == 2) {

        ////Hero Details
        string nameOfPrevHero;
        string typePrev;
        int numOfCreaturesPrev;
        int numOfZombiesPrev;
        int numOfVampiresPrev;
        int numOfArcherPrev;
        int numOfWizardsPrev;
        int numOfBlackDragonPrev;
        bool myTurn;
        double goldPrev;
        bool alivePrev;
        bool WspecialPrev;

        int round = 0;
        int numOfPlayeres;
        string filePath;
        filePath = string(argv[0]);
        int counter = 0;
        for (int i = filePath.length() - 1; i > 0; i--) {
            if (filePath[i] != '/') {
                counter++;
            } else {
                break;
            }
        }
        filePath = filePath.substr(0,filePath.length() - counter);
        //filePath="/home/zahi/CLionProjects/ex5/cmake-build-debug/";
        string gFilePath = filePath + "game";
        string gameDetailsFilePath = gFilePath + "/Game.txt";
        ifstream gameDetailsFile(gameDetailsFilePath);
        string currentLine;
        if (gameDetailsFile.is_open()) {
            getline(gameDetailsFile, currentLine);
            round = stoi(currentLine);
            getline(gameDetailsFile, currentLine);
            heroNum = stoi(currentLine);
            getline(gameDetailsFile, currentLine);
            numOfPlayeres = stoi(currentLine);
        }
        Hero **previousHeroes = new Hero *[numOfPlayeres];
        for (int j = 0; j < numOfPlayeres; ++j) {
            string nameOfFolderHero;
            getline(gameDetailsFile, nameOfFolderHero);
            nameOfPrevHero = nameOfFolderHero;
            string thisHeroFolderPath = filePath + nameOfFolderHero + "/" + nameOfFolderHero + ".txt";
            ifstream thisHeroDetails(thisHeroFolderPath);
            string currentLineOfHero;
            if (thisHeroDetails.is_open()) {
                getline(thisHeroDetails, currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                typePrev = currentLineOfHero;
                getline(thisHeroDetails, currentLineOfHero);
                numOfCreaturesPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                numOfZombiesPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                numOfVampiresPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                numOfArcherPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                numOfWizardsPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                numOfBlackDragonPrev = stoi(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                if (currentLineOfHero == "true") {
                    myTurn = true;
                } else {
                    myTurn = false;
                }
                getline(thisHeroDetails, currentLineOfHero);
                goldPrev = stod(currentLineOfHero);
                getline(thisHeroDetails, currentLineOfHero);
                if (currentLineOfHero == "true") {
                    alivePrev = true;
                } else {
                    alivePrev = false;
                }
                getline(thisHeroDetails, currentLineOfHero);
                if (currentLineOfHero == "true") {
                    WspecialPrev = true;
                } else {
                    WspecialPrev = false;

                }
                if (typePrev == "Thief") {
                    previousHeroes[j] = new Thief(nameOfPrevHero, typePrev, numOfCreaturesPrev, numOfZombiesPrev,
                                                  numOfVampiresPrev, numOfArcherPrev, numOfWizardsPrev,
                                                  numOfBlackDragonPrev, myTurn, goldPrev, alivePrev,WspecialPrev);
                } else if (typePrev == "Necromancer") {
                    previousHeroes[j] = new Necromancer(nameOfPrevHero, typePrev, numOfCreaturesPrev, numOfZombiesPrev,
                                                        numOfVampiresPrev, numOfArcherPrev, numOfWizardsPrev,
                                                        numOfBlackDragonPrev, myTurn, goldPrev, alivePrev,WspecialPrev);
                } else if (typePrev == "Warrior") {
                    previousHeroes[j] = new Warrior(nameOfPrevHero, typePrev, numOfCreaturesPrev, numOfZombiesPrev,
                                                    numOfVampiresPrev, numOfArcherPrev, numOfWizardsPrev,
                                                    numOfBlackDragonPrev, myTurn, goldPrev, alivePrev,WspecialPrev);
                }
            }
            thisHeroDetails.close();
        }
        gameDetailsFile.close();
        game = new Play(round, numOfPlayeres, previousHeroes);
        for (int k = 0; k < numOfPlayeres; ++k) {
            delete previousHeroes[k];
        }
        delete[] previousHeroes;
    }
    int choice = 0;
    while (choice != 7) {
        if (!game->isAliveByIndex(heroNum)) {
            heroNum++;
            choice = 6;
        } else if (game->isThereAWinner() != -1 && game->getRound() > 3) {
            choice = 7;
        } else {
            cout << "Welcome " << game->getNameByIndex(heroNum) << "\n";
            cout << "What is your next step in the path to victory?\n";
            cout << "1. Attack\n";
            cout << "2. Get daily gold\n";
            cout << "3. Buy creatures\n";
            cout << "4. Show details\n";
            cout << "5. Special skill\n";
            cout << "6. End of my turn\n";
            cout << "7. Exit\n";
            cin >> choice;
        }
        switch (choice) {
            case 1: {
                int choice1 = 0;
                cout << "1. Show me my opponents\n";
                cout << "2. Attack\n";
                cin >> choice1;
                switch (choice1) {
                    case 1: {
                        for (int j = 0; j < game->getNumOfPlayers(); ++j) {
                            if (game->getNameByIndex(j) != game->getNameByIndex(heroNum) &&
                                game->getTypeByIndex(j) == "Warrior" && game->isAliveByIndex(j)) {
                                cout << game->getNameByIndex(j) << game->getTypeByIndex(j)
                                     << "\n";
                            }
                        }
                        for (int j = 0; j < game->getNumOfPlayers(); ++j) {
                            if (game->getNameByIndex(j) != game->getNameByIndex(heroNum) &&
                                game->getTypeByIndex(j) == "Thief" && game->isAliveByIndex(j)) {
                                cout << game->getNameByIndex(j) << game->getTypeByIndex(j)
                                     << "\n";
                            }
                        }
                        for (int j = 0; j < game->getNumOfPlayers(); ++j) {
                            if (game->getNameByIndex(j) != game->getNameByIndex(heroNum) &&
                                game->getTypeByIndex(j) == "Necromancer" && game->isAliveByIndex(j)) {
                                cout  << game->getNameByIndex(j) << game->getTypeByIndex(j)
                                     << "\n";
                            }
                        }
                        char a = 0;
                        while (a != '\n') {
                            cin.get();
                            cin.get(a);
                        }
                        break;
                    }
                    case 2: {
                        if (game->getRound() < 4) {
                            cout << "You can't attack yet!\n";
                            break;
                        }
                        string op;
                        NotExistHeroException myex;
                        cout << "Please enter your opponent name:\n";
                        cin >> op;
                        try {
                            if (game->searchPlayer(op) != -1) {

                            } else {
                                throw myex;
                            }
                        } catch (exception &e) {
                            cout << e.what();

                            break;
                        }
                        try {
                            if (game->isAliveByIndex(game->searchPlayer(op))) {

                            } else {
                                throw myex;
                            }
                        } catch (exception &e) {
                            cout << e.what();

                            break;
                        }
                        Hero &heroToAttack = game->getHeroR(game->searchPlayer(op));
                        Hero &attackingHero = game->getHeroR(heroNum);
                        game->printArmyByIndex(heroNum);
                        int opIndex = game->searchPlayer(op);
                        game->printArmyByIndex(opIndex);
                        while (game->getNumOfCreatures(heroNum) != 0 && game->getNumOfCreatures(opIndex)) {
                            cout  << game->getNameByIndex(heroNum) << "'s turn:\n";
                            string attackingCreature1;
                            string creatureToAttack1;
                            cin >> attackingCreature1 >> creatureToAttack1;
                            heroToAttack = game->getHeroR(opIndex);
                            attackingHero = game->getHeroR(heroNum);
                            NotExistCreatureException ex;
                            while (!game->isTypeExist(attackingCreature1, attackingHero)) {
                                try {
                                    if (game->isTypeExist(attackingCreature1, attackingHero)) {
                                        break;
                                    } else {
                                        throw ex;
                                    }
                                } catch (exception &e) {
                                    cout << e.what();
                                    cout << "please enter attacking creature name\n";
                                    cin >> attackingCreature1;
                                }
                            }
                            while (!game->isTypeExist(creatureToAttack1, heroToAttack)) {
                                try {
                                    if (game->isTypeExist(creatureToAttack1, heroToAttack)) {
                                        break;
                                    } else {
                                        throw ex;
                                    }
                                } catch (exception &e) {
                                    cout << e.what();
                                    cout << "please enter creature to attack name\n";
                                    cin >> creatureToAttack1;
                                }
                            }
                            Creature &creatureToAttack = game->getCreatureR(creatureToAttack1, opIndex);
                            Creature &attackingCreature = game->getCreatureR(attackingCreature1, heroNum);
                            game->attack(attackingHero, heroToAttack, attackingCreature, creatureToAttack);
                            game->printArmyByIndex(opIndex);
                            game->printArmyByIndex(heroNum);
                            if (game->getNumOfCreatures(opIndex) == 0) {
                                cout << "You have been victorious\n";
                                game->killThisHero(opIndex);
                                if (game->isThereAWinner() != -1) {
                                    cout << game->getNameByIndex(game->isThereAWinner()) << " is the winner\n";
                                }
                                break;
                            } else {
                                cout << game->getNameByIndex(opIndex) << "'s turn:\n";
                                cin >> attackingCreature1 >> creatureToAttack1;
                                //attackingHero = game->getHeroR(opIndex);
                                Hero &heroToAttackNewR = game->getHeroR(heroNum);
                                Hero &attackingHeroNewR = game->getHeroR(opIndex);
                                //heroToAttack = game->getHeroR(heroNum);

                                NotExistCreatureException ex1;
                                while (!game->isTypeExist(attackingCreature1, attackingHeroNewR)) {
                                    try {
                                        if (game->isTypeExist(attackingCreature1, attackingHeroNewR)) {
                                            break;
                                        } else {
                                            throw ex1;
                                        }
                                    } catch (exception &e) {
                                        cout << e.what() << endl;
                                        cout << "please enter attacking creature name\n";
                                        cin >> attackingCreature1;
                                    }
                                }
                                while (!game->isTypeExist(creatureToAttack1, heroToAttackNewR)) {
                                    try {
                                        if (game->isTypeExist(creatureToAttack1, heroToAttackNewR)) {
                                            break;
                                        } else {
                                            throw ex1;
                                        }
                                    } catch (exception &e) {
                                        cout << e.what() << endl;
                                        cout << "please enter creature to attack name\n";
                                        cin >> creatureToAttack1;
                                    }
                                }
                                Creature &creatureToAttackop = game->getCreatureR(creatureToAttack1, heroNum);
                                Creature &attackingCreaturop = game->getCreatureR(attackingCreature1, opIndex);
                                game->attack(attackingHeroNewR, heroToAttackNewR, attackingCreaturop,
                                             creatureToAttackop);
                                game->printArmyByIndex(heroNum);
                                game->printArmyByIndex(opIndex);
                                if (game->getNumOfCreatures(heroNum) == 0) {
                                    cout << "You have been perished\n";

                                    game->killThisHero(heroNum);
                                    game->startHeroTurn(heroNum);
                                    heroNum = game->getNextAliveHero(heroNum);
                                    if (game->isThereAWinner() != -1) {
                                        cout << game->getNameByIndex(game->isThereAWinner()) << " is the winner\n";
                                    }
                                    break;
                                }
                            }
                        }
                    }
                }

                break;
            }
            case 2: {
                game->getDailyGold(heroNum);
                break;
            }
            case 3: {
                cout << "1.Buy Zombies.\n";
                cout << "2.Buy Archers.\n";
                cout << "3.Buy Vampire.\n";
                cout << "4.Buy Wizard.\n";
                cout << "5.Buy Black Dragon.\n";
                int choice3 = 0;
                cin >> choice3;
                switch (choice3) {
                    case 1: {
                        cout << "Attack level:" << 2 << ", Defense level:" << 5 << "\n";
                        int amount = 0;
                        cout << "please enter amount\n";
                        cin >> amount;
                        NotEnoughmoneyException moEx;
                        try {
                            if (amount * 50 <= game->getGoldByIndex(heroNum)) {
                            } else {
                                throw moEx;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                            break;
                        }
                        game->buyCreatureForHero(heroNum, "Zombie", amount);
                        break;

                    }
                    case 2: {
                        cout << "Attack level:" << 5 << ", Defense level:" << 4 << "\n";
                        int amount = 0;
                        cout << "please enter amount\n";
                        cin >> amount;
                        NotEnoughmoneyException moEx;
                        try {
                            if (amount * 90 <= game->getGoldByIndex(heroNum)) {

                            } else {
                                throw moEx;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                            break;
                        }
                        game->buyCreatureForHero(heroNum, "Archer", amount);

                        break;

                    }
                    case 3: {
                        cout << "Attack level:" << 4 << ", Defense level:" << 4 << "\n";
                        int amount = 0;
                        cout << "please enter amount\n";
                        cin >> amount;
                        NotEnoughmoneyException moEx;
                        try {
                            if (amount * 80 <= game->getGoldByIndex(heroNum)) {
                            } else {
                                throw moEx;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                            break;
                        }
                        game->buyCreatureForHero(heroNum, "Vampire", amount);
                        break;

                    }
                    case 4: {
                        cout << "Attack level:" << 8 << ", Defense level:" << 2 << "\n";
                        int amount = 0;
                        cout << "please enter amount\n";
                        cin >> amount;
                        NotEnoughmoneyException moEx;
                        try {
                            if (amount * 150 <= game->getGoldByIndex(heroNum)) {
                            } else {
                                throw moEx;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                            break;
                        }
                        game->buyCreatureForHero(heroNum, "Wizard", amount);
                        break;

                    }
                    case 5: {
                        cout << "Attack level:" << 9 << ", Defense level:" << 10 << "\n";
                        int amount = 0;
                        cout << "please enter amount\n";
                        cin >> amount;
                        NotEnoughmoneyException moEx;
                        try {
                            if (amount * 200 <= game->getGoldByIndex(heroNum)) {
                            } else {
                                throw moEx;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                            break;
                        }
                        game->buyCreatureForHero(heroNum, "BlackDragon", amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                game->getHeroDetails(heroNum);
                break;
            }
            case 5: {
                if (game->getTypeByIndex(heroNum) == "Warrior") {
                    if (game->getWspecialSkillByIndex(heroNum)) {
                        game->heroSpecialSkill(heroNum);
                    }
                    break;
                } else if (game->getTypeByIndex(heroNum) == "Thief") {
                    if(game->getSpecialSkillByIndex(heroNum)==true) {
                        string heroToStill;
                        cout << "Please insert hero name:\n";
                        cin >> heroToStill;
                        NotExistHeroException myex;
                        try {
                            if (game->searchPlayer(heroToStill) != -1) {
                                game->heroSpecialSkill(heroNum, game->getHeroR(game->searchPlayer(heroToStill)));
                            } else {
                                throw myex;
                            }
                        } catch (exception &e) {
                            cout << e.what() << endl;
                        }
                    }
                        break;

                } else {

                    game->heroSpecialSkill(heroNum);
                    break;//// necroman play
                }

            }
            case 6: {
                if (game->getTypeByIndex(heroNum) == "Warrior") {
                    game->setWspecialSkillByIndex(heroNum);
                }
                game->startHeroTurn(heroNum);
                heroNum = game->getNextAliveHero(heroNum);
                break;
            }
            case 7: {
                if(game->isThereAWinner() == -1){
                    game->saveGame(heroNum, pathS);
                }
                delete game;
                return  0;

            }
            default: {
		break;
            }
        }
    }


    return 0;
}

