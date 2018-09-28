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
	virtual ~Spell();
	// methods
	void giveWeaponSpecifications();
};

} /* namespace std */

#endif /* SPELL_H_ */
