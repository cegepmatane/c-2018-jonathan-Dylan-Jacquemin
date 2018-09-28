/*
 * Archer.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef ARCHER_H_
#define ARCHER_H_

#include "Character.h"

namespace std {

class Archer : public Character {
public:
	Archer();
	virtual ~Archer();
	// methods
	bool isDead();
	void useWeapon(Character&);
};

} /* namespace std */

#endif /* ARCHER_H_ */
