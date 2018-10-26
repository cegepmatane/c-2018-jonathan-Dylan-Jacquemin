#pragma once

#include "Character.h"

using namespace std;

class Priestess : public Character {
public:
	Priestess();
	Priestess(int);
	Priestess(Weapon*);
	Priestess(int, Weapon*);
	virtual ~Priestess();

	// methods
	void initProp();
	std::string getName();
	bool isDead();
	void useWeapon(Character&);
	void changeWeapon(Weapon*);
	void dealDamage(Character&, int);
	std::string exportDatas();
	void pressA(World*);
	void pressE(World*);
	std::string getPath();
};

