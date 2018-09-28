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
	return this->hitPoints==0;
}

void Character::useWeapon(Character& character) {

}

} /* namespace std */
