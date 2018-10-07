/*
 * Weapon.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef WEAPON_H_
#define WEAPON_H_

#include <iostream>
#include <fstream>
#include <sstream>

namespace std {

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
	virtual string exportDatas();
};

} /* namespace std */

#endif /* WEAPON_H_ */
