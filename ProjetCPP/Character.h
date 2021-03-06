#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "conio.h"
#include <thread>
#include <chrono>

#include "Weapon.h"

using namespace std;

class World;

class Character {

	public:
		Character();
		Character(int);
		Character(Weapon*);
		Character(int, Weapon*);
		virtual ~Character();

		// attributes
		int hitPoints;
		int baseHitPoints;
		std::string name;
		Weapon* weapon;

		// methods
		virtual void initProp();
		virtual std::string getName() {
			return "";
		};
		virtual bool isDead() {
			return true;
		};
		virtual int numberMissingHP() {
			return 0;
		};
		virtual void useWeapon(Character&);
		virtual void changeWeapon(Weapon*);
		virtual void dealDamage(Character&, int);
		virtual std::string exportDatas();
		virtual void pressA(World*);
		virtual void pressE(World*);
		virtual std::string getPath();
		virtual void usePotion();
		virtual void getHealed(int);
};
