/*
 * Archer.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Archer.h"

namespace std {

Archer::Archer() {
	this->hitPoints = 16;

}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

bool Archer::isDead() {
	if (hitPoints<=0) return true;
	else return false;
}

void Archer::useWeapon(Character& character) {

}

} /* namespace std */
