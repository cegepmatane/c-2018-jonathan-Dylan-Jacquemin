/*
 * Mage.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Mage.h"

namespace std {

Mage::Mage() {
	this->initProp();
}

Mage::Mage(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Mage::Mage(Weapon& weapon) {
	this->initProp();
	this->weapon = weapon;
}

Mage::Mage(int hitPoints, Weapon& weapon) {
	this->hitPoints = hitPoints;
	this->weapon = weapon;
}

Mage::~Mage() {
	// TODO Auto-generated destructor stub
}

void Mage::initProp() {
	this->name = "Mage";

	ifstream mageSource("data/mage.csv");

	if (mageSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream mageFile("data/mage.csv", ios::out | ios::trunc);
		if(mageFile) {
			mageFile << "12;";
			mageFile.close();
		}
		else
			cerr << "Error while opening the file \"mage.csv\"" << endl;
	}

	mageSource.close();
	mageSource.open("data/mage.csv");

	string line;

	while(!mageSource.eof()) {
		getline(mageSource, line);

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

string Mage::getName() {
	return this->name;
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
