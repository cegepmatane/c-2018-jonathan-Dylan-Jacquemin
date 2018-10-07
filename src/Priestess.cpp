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

Priestess::Priestess(int hitPoints) {
	this->hitPoints = hitPoints;
}

Priestess::Priestess(Weapon& weapon) {
	Priestess();
	this->weapon = weapon;
}

Priestess::Priestess(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Priestess::~Priestess() {
	// TODO Auto-generated destructor stub
}

bool Priestess::isDead() {
	return this->hitPoints==0;
}

void Priestess::useWeapon(Character& character) {
	character.hitPoints = character.hitPoints - this->weapon.damageAmmount;
}

void Priestess::changeWeapon(Weapon& weapon) {
	this->weapon = weapon;
}

string Priestess::exportDatas() {
	stringstream xml;
	xml << "<Priestess><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Priestess>";
	return xml.str();
}

} /* namespace std */
