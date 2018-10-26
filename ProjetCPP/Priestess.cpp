#include "Priestess.h"
#include "World.h"

Priestess::Priestess() {
	this->initProp();
}

Priestess::Priestess(int hitPoints) {
	this->initProp();
	this->hitPoints = hitPoints;
}

Priestess::Priestess(Weapon* weapon) {
	this->initProp();
	this->weapon = weapon;
}

Priestess::Priestess(int hitPoints, Weapon* weapon) {
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
	character.hitPoints = character.hitPoints - this->weapon->damageAmmount;
}

void Priestess::changeWeapon(Weapon* weapon) {
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

void Priestess::pressA(World* world) {
	cout << "- " << this->getName() << " : I won't let you down, my friends !" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));

	for (Character* character : world->charactersList) {
		this->useWeapon(*character);
	}
	// TODO : define a baseHP attribute in std::Character
	cout << "You healed all your team of " << 0 - this->weapon->damageAmmount << "HP\n" << endl;
}

void Priestess::pressE(World* world) {
	cout << "- " << world->currentCharacter->getName() << " : Come here, I will heal you~" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));

	world->currentCharacter->useWeapon(*world->charactersList.at(world->gameTurn % 2));
	// TODO : define a baseHP attribute in std::Character
	cout << "You healed an ally for " << 0 - world->currentCharacter->weapon->damageAmmount << "HP\n" << endl;
}

string Priestess::getPath() {
	return "priestess.png";
}