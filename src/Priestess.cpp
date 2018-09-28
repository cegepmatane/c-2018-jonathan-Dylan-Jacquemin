/*
 * Priestess.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Priestess.h"

namespace std {

Priestess::Priestess() {
	this->hitPoints = 20;
}

Priestess::~Priestess() {
	// TODO Auto-generated destructor stub
}

bool Priestess::isDead() {
	if (hitPoints<=0) return true;
	else return false;
}

void Priestess::useWeapon(Character& character) {
}

} /* namespace std */
