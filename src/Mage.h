/*
 * Mage.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef MAGE_H_
#define MAGE_H_

#include "Character.h"

namespace std {

class Mage : public Character {
public:
	Mage();
	virtual ~Mage();
	// methods
	bool isDead();
	void useWeapon(Character&);
};

} /* namespace std */

#endif /* MAGE_H_ */
