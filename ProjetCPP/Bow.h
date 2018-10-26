#pragma once

#include "Weapon.h"

using namespace std;

class Bow : public Weapon{
public:
	Bow();
	Bow(int);
	virtual ~Bow();

	// methods
	void initProp();
	void giveWeaponSpecifications();
	std::string exportDatas();
	int operator+(Weapon&);
};
