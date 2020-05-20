Heroes: Creature.o Archer.o BlackDragon.o Zombie.o Wizard.o Vampire.o Hero.o Warrior.o Thief.o Necromancer.o InvalidUserNameException.o NotEnoughMoneyException.o NotExistCreatureException.o NotExistHeroException.o Play.o main.o
	g++ main.o Creature.o Archer.o BlackDragon.o Zombie.o Wizard.o Vampire.o Hero.o Warrior.o Thief.o Necromancer.o InvalidUserNameException.o NotEnoughMoneyException.o NotExistCreatureException.o NotExistHeroException.o Play.o -o Heroes

Archer.o: Archer.cpp Archer.h Creature.h
	g++ -c Archer.cpp

BlackDragon.o: BlackDragon.cpp BlackDragon.h Creature.h
	g++ -c BlackDragon.cpp

Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp

Hero.o: Hero.cpp Hero.h Creature.h InvalidUserNameException.h Vampire.h Archer.h Zombie.h Wizard.h BlackDragon.h
	g++ -c Hero.cpp

InvalidUserNameException.o: InvalidUserNameException.cpp InvalidUserNameException.h
	g++ -c InvalidUserNameException.cpp

main.o: main.cpp Warrior.h Hero.h Creature.h InvalidUserNameException.h Thief.h Necromancer.h NotExistHeroException.h Play.h NotExistCreatureException.h NotEnoughMoneyException.h
	g++ -c main.cpp

Necromancer.o: Necromancer.cpp Necromancer.h Hero.h Creature.h InvalidUserNameException.h Zombie.h
	g++ -c Necromancer.cpp

NotEnoughMoneyException.o: NotEnoughMoneyException.cpp NotEnoughMoneyException.h
	g++ -c NotEnoughMoneyException.cpp

NotExistCreatureException.o: NotExistCreatureException.cpp NotExistCreatureException.h
	g++ -c NotExistCreatureException.cpp

NotExistHeroException.o: NotExistHeroException.cpp NotExistHeroException.h
	g++ -c NotExistHeroException.cpp

Play.o: Play.cpp Play.h Hero.h Creature.h InvalidUserNameException.h Warrior.h Thief.h Necromancer.h
	g++ -c Play.cpp

Thief.o: Thief.cpp Thief.h Hero.h Creature.h InvalidUserNameException.h NotExistHeroException.h Necromancer.h
	g++ -c Thief.cpp

Vampire.o: Vampire.cpp Vampire.h Creature.h
	g++ -c Vampire.cpp

Warrior.o: Warrior.cpp Warrior.h Hero.h Creature.h InvalidUserNameException.h
	g++ -c Warrior.cpp

Wizard.o: Wizard.cpp Wizard.h Creature.h
	g++ -c Wizard.cpp

Zombie.o: Zombie.cpp Zombie.h Creature.h
	g++ -c Zombie.cpp
