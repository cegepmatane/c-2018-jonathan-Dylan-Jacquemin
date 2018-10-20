/*
 * Priestess.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Priestess.h"

namespace std {

Priestess::Priestess() {
	this->initProp();
}

Priestess::Priestess(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Priestess::Priestess(Weapon& weapon) {
	this->initProp();
	this->weapon = weapon;
}

Priestess::Priestess(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Priestess::~Priestess() {
	// TODO Auto-generated destructor stub
}

void Priestess::initProp() {
	this->name = "Priestess";

	ifstream priestessSource("data/priestess.csv");

	if (priestessSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream priestessFile("data/priestess.csv", ios::out | ios::trunc);
		if(priestessFile) {
			priestessFile << "20;";
			priestessFile.close();
		}
		else
			cerr << "Error while opening the file \"priestess.csv\"" << endl;
	}

	priestessSource.close();
	priestessSource.open("data/priestess.csv");

	string line;

	while(!priestessSource.eof()) {
		getline(priestessSource, line);

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

string Priestess::getName() {
	return this->name;
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

void Priestess::dealDamage(Character& character, int damageAmmount) {
	character.hitPoints = character.hitPoints - damageAmmount;
}

string Priestess::exportDatas() {
	stringstream xml;
	xml << "<Priestess><hitPoints>" << this->hitPoints << "</hitPoints>" << "</Priestess>";
	return xml.str();
}

} /* namespace std */
