/*
 * Spell.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef SPELL_H_
#define SPELL_H_

#include "Weapon.h"

namespace std {

class Spell : public Weapon {
public:
	Spell();
	Spell(int);
	virtual ~Spell();
	// methods
	void initProp();
	void giveWeaponSpecifications();
	string exportDatas();
	int operator+(Weapon&);
};

} /* namespace std */

#endif /* SPELL_H_ */
