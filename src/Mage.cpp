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

Mage::Mage(int hitPoints) {
	this->hitPoints = hitPoints;
}

Mage::Mage(Weapon& weapon) {
	Mage();
	this->weapon = weapon;
}

Mage::Mage(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
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

void Mage::changeWeapon(Weapon& weapon) {
	this->weapon = weapon;
}

string Mage::exportDatas() {
	stringstream xml;
	xml << "<Mage><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Mage>";
	return xml.str();
}

} /* namespace std */
