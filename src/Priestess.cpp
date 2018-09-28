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
	return this->hitPoints==0;
}

void Priestess::useWeapon(Character& character) {
}

} /* namespace std */
