#pragma once

#include "Character.h"

using namespace std;

class Mage : public Character {
	public:
		Mage();
		Mage(int);
		Mage(Weapon*);
		Mage(int, Weapon*);
		virtual ~Mage();

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
		void usePotion();
		void getHealed(int);
};
