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

Archer::Archer(int hitPoints) {
	this->hitPoints = hitPoints;
}

Archer::Archer(Weapon& weapon) {
	Archer();
	this->weapon = weapon;
}

Archer::Archer(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
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

void Archer::changeWeapon(Weapon& weapon) {
	this->weapon = weapon;
}

string Archer::exportDatas() {
	stringstream xml;
	xml << "<Archer><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Archer>";
	return xml.str();
}


} /* namespace std */
