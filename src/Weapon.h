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

namespace std {

class Weapon {
public:
	Weapon();
	virtual ~Weapon();
	// attributes
	int damageAmmount;
	// methods
	virtual void giveWeaponSpecifications();
	virtual void exportDatas();
};

} /* namespace std */

#endif /* WEAPON_H_ */
