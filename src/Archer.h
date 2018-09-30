/*
 * Archer.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Character.h"
#include "Weapon.h"

namespace std {

class Archer : public Character {
public:
	Archer();
	Archer(int);
	Archer(Weapon&);
	Archer(int, Weapon&);
	virtual ~Archer();
	// methods
	bool isDead();
	void useWeapon(Character&);
	void changeWeapon(Weapon&);
	void exportDatas();
};

} /* namespace std */

#endif /* ARCHER_H_ */
