/*
 * Archer.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Archer.h"

namespace std {

Archer::Archer() {
	this->initProp();
}

Archer::Archer(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Archer::Archer(Weapon& weapon) {
	this->initProp();
	this->weapon = weapon;
}

Archer::Archer(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Archer::~Archer() {
	// TODO Auto-generated destructor stub
}

void Archer::initProp() {
	ifstream archerSource;
	archerSource.open("data/archer.csv");

	string line;

	while(!archerSource.eof()) {
		getline(archerSource, line);

		unsigned int startPosition = 0;
		unsigned int endPosition = 0;

		do {
			endPosition = line.find(";", startPosition);
			string value = line.substr(startPosition, endPosition - startPosition);
			this->hitPoints = stoi(value);
			startPosition = endPosition + 1;
		}
		while((startPosition !=0) && (line.length() != startPosition));
	}
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
