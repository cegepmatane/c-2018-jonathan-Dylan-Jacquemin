/*
 * Priestess.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef PRIESTESS_H_
#define PRIESTESS_H_

#include "Character.h"
#include "Weapon.h"

namespace std {

class Priestess : public Character {
public:
	Priestess();
	Priestess(int);
	Priestess(Weapon&);
	Priestess(int, Weapon&);
	virtual ~Priestess();
	// methods
	void initProp();
	string getName();
	bool isDead();
	void useWeapon(Character&);
	void changeWeapon(Weapon&);
	string exportDatas();
};

} /* namespace std */

#endif /* PRIESTESS_H_ */
