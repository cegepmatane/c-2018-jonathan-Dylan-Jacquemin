#pragma once

#include "Weapon.h"

using namespace std;

class Spell : public Weapon {
public:
	Spell();
	Spell(int);
	virtual ~Spell();

	// methods
	void initProp();
	void giveWeaponSpecifications();
	std::string exportDatas();
	int operator+(Weapon&);
	std::string getPath();
};
