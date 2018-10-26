#include "World.h"

World::World() {

	// Weapon creation
	Weapon* bow = new Bow();
	Weapon* spell = new Spell();
	Weapon* staff = new Staff();

	weaponsList.push_back(bow);
	weaponsList.push_back(spell);
	weaponsList.push_back(staff);

	// Character creation
	Character* archer = new Archer(bow);
	Character* mage = new Mage(spell);
	Character* priestess = new Priestess(staff);

	charactersList.push_back(archer);
	charactersList.push_back(mage);
	charactersList.push_back(priestess);

	Character* ennemy = new Mage(100, spell);
	charactersList.push_back(ennemy);

	this->gameTurn = 0;

	this->playingCharacterNumber = 0;

	this->currentCharacter = this->charactersList.at(this->playingCharacterNumber);
	cout << "You currently are playing archer ("
		<< this->currentCharacter->hitPoints << "HP) \n" << endl;

}

World::~World() {

}

void World::nextCharacter() {
	this->playingCharacterNumber = (this->playingCharacterNumber + 1) % 3;
	this->currentCharacter = this->charactersList.at(this->playingCharacterNumber);
}

void World::saveState() {
	// Data export
	ofstream worldFile;
	worldFile.open("data/world.xml");

	worldFile << "<World>" << endl;
	worldFile << "<Character>" << endl;
	for (Character* character : charactersList) {
		worldFile << character->exportDatas() << endl;
	}
	worldFile << "</Character>" << endl;
	worldFile << "<Spell>" << endl;
	for (Weapon* weapon : weaponsList) {
		worldFile << weapon->exportDatas() << endl;
	}
	worldFile << "</Spell>" << endl;
	worldFile << "</World>";
	worldFile.close();

	cout << "Game finished, exported datas can be found on ./data/world.xml" << endl;
}

