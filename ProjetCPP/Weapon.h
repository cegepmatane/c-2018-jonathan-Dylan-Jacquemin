#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

class Weapon {
	public:
		Weapon();
		Weapon(int);
		virtual ~Weapon();

		// attributes
		int damageAmmount;

		// methods
		virtual void initProp();
		virtual void giveWeaponSpecifications();
		virtual std::string exportDatas();
		virtual int operator+(Weapon&);
};
