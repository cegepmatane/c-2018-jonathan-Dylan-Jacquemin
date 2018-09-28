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
	return this->hitPoints==0;
}

void Archer::useWeapon(Character& character) {

}

} /* namespace std */
