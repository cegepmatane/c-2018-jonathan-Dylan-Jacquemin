/*
 * Spell.cpp
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#include "Spell.h"

namespace std {

Spell::Spell() {
	this->initProp();
}

Spell::Spell(int damageAmmount) {
	this->initProp();
	this->damageAmmount = damageAmmount;
}

Spell::~Spell() {

}

void Spell::initProp() {
	ifstream spellSource("data/spell.csv");

	if (spellSource.peek() == std::ifstream::traits_type::eof()) {
		ofstream spellFile("data/spell.csv", ios::out | ios::trunc);
		if(spellFile) {
			spellFile << "4;";
			spellFile.close();
		}
		else
			cerr << "Error while opening the file \"spell.csv\"" << endl;
	}

	spellSource.close();
	spellSource.open("data/spell.csv");

	string line;

	while(!spellSource.eof()) {
		getline(spellSource, line);

		unsigned int startPosition = 0;
		unsigned int endPosition = 0;

		do {
			endPosition = line.find(";", startPosition);
			string value = line.substr(startPosition, endPosition - startPosition);
			this->damageAmmount = stoi(value);
			startPosition = endPosition + 1;
		}
		while((startPosition !=0) && (line.length() != startPosition));
	}
}

void Spell::giveWeaponSpecifications() {
	cout << "A powerful magic fireball ! Inflicts " << this->damageAmmount << " damage." << endl;
}

string Spell::exportDatas() {
	stringstream xml;
	xml << "<Spell><damageAmmount>" << this->damageAmmount << "</damageAmmount>" << "</Spell>";
	return xml.str();
}

} /* namespace std */
