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

Character::Character(int hitPoints) {
	this->hitPoints = hitPoints;
}

Character::Character(Weapon& weapon) {
	this->hitPoints = 0;
	this->weapon = weapon;
}

Character::~Character() {
	// TODO Auto-generated destructor stub
}

bool Character::isDead() {
	return this->hitPoints==0;
}

void Character::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

void Character::exportDatas() {
}

} /* namespace std */
