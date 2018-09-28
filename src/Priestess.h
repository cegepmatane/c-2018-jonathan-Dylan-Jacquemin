/*
 * Priestess.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef PRIESTESS_H_
#define PRIESTESS_H_

#include "Character.h"

namespace std {

class Priestess : public Character {
public:
	Priestess();
	virtual ~Priestess();
	// methods
	bool isDead();
	void useWeapon(Character&);
};

} /* namespace std */

#endif /* PRIESTESS_H_ */
