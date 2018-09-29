/*
 * Mage.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Mage.h"

namespace std {

Mage::Mage() {
	this->hitPoints = 12;
}

Mage::Mage(Weapon& weapon) {
	this->hitPoints = 12;
	this->weapon = weapon;
}

Mage::~Mage() {
	// TODO Auto-generated destructor stub
}

bool Mage::isDead() {
	return this->hitPoints==0;
}

void Mage::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

} /* namespace std */
