/*
 * Spell.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Spell.h"

namespace std {

Spell::Spell() {
	this->damageAmmount = 4;
}

Spell::~Spell() {

}

void Spell::giveWeaponSpecifications() {
	cout << "A powerful magic fireball ! Inflicts " << this->damageAmmount << " damage." << endl;
}

} /* namespace std */
