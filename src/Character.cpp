/*
 * Character.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Character.h"

namespace std {

Character::Character() {}

Character::Character(int hitPoints) {}

Character::Character(Weapon& weapon) {}

Character::Character(int, Weapon&){}

Character::~Character() {}

void Character::initProp() {}

void Character::useWeapon(Character& character) {}

void Character::changeWeapon(Weapon& weapon) {}

string Character::exportDatas() {return "";}

} /* namespace std */
