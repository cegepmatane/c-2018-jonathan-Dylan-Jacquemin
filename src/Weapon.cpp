/*
 * Weapon.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Weapon.h"

namespace std {

Weapon::Weapon() {
	this->damageAmmount = 0;
}

Weapon::~Weapon() {

}

void Weapon::giveWeaponSpecifications() {
	cout << "A weapon. No more. No less." << endl;
}

void Weapon::exportDatas() {

}

} /* namespace std */
