#pragma once

#include "Character.h"

using namespace std;

class Archer : public Character {
	public:
		Archer();
		Archer(int);
		Archer(Weapon*);
		Archer(int, Weapon*);
		virtual ~Archer();

		// methods
		void initProp();
		std::string getName();
		bool isDead();
		int numberMissingHP();
		void useWeapon(Character&);
		void changeWeapon(Weapon*);
		void dealDamage(Character&, int);
		std::string exportDatas();
		void pressA(World*);
		void pressE(World*);
		std::string getPath();
};

