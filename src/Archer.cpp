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

Archer::Archer(Weapon& weapon) {
	this->hitPoints = 16;
	this->weapon = weapon;
}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

bool Archer::isDead() {
	return this->hitPoints==0;
}

void Archer::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

} /* namespace std */
