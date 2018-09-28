/*
 * Character.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Character.h"

namespace std {

Character::Character() {
	this->hitPoints = 0;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

bool Character::isDead() {
	if (this->hitPoints <= 0) {
		return true;
	}
}

void Character::useWeapon() {

}

} /* namespace std */
