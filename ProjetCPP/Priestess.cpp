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
			this->baseHitPoints = stoi(value);
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

int Priestess::numberMissingHP() {
	cout << "current " << this->hitPoints << endl;
	cout << "base " << this->baseHitPoints << endl;
	cout << "calc " << this->baseHitPoints - this->hitPoints << endl;
	return this->baseHitPoints - this->hitPoints;
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
		character->getHealed(-(this->weapon->damageAmmount));
		cout << "ALED" << -this->weapon->damageAmmount << endl;
	}
	cout << "You healed all your team." << endl;
}

void Priestess::pressE(World* world) {
	cout << "- " << world->currentCharacter->getName() << " : Come here, I will heal you~" << endl;
	this_thread::sleep_for(chrono::milliseconds(1000));

	world->charactersList.at(world->gameTurn % 2)->getHealed(-(this->weapon->damageAmmount));
	cout << "You healed an ally." << endl;
}

string Priestess::getPath() {
	return "priestess.png";
}

void Priestess::usePotion() {
	if (this->numberMissingHP() >= (int)(this->baseHitPoints / 4)) {
		cout << "baseHP / 4 in int format " << (int)(this->baseHitPoints / 4) << endl;
		cout << "The potion made you regain " << this->numberMissingHP() << "HPs" << endl;
		this->hitPoints = this->baseHitPoints;
		cout << this->hitPoints << endl;
		cout << this->baseHitPoints << endl;
	}
	else {
		cout << "baseHP / 4 in int format " << (int)(this->baseHitPoints / 4) << endl;
		cout << "The potion made you regain " << (int)(this->baseHitPoints / 4) << "HPs" << endl;
		this->hitPoints += (int)(this->baseHitPoints / 4);
	}
}

void Priestess::getHealed(int healAmmount) {
	if (this->numberMissingHP() >= healAmmount) {
		cout << this->name << " has been healed of " << this->numberMissingHP() << "HPs." << endl;
		this->hitPoints = this->baseHitPoints;
	}
	else {
		cout << this->name << " has been healed of " << healAmmount << "HPs" << endl;
		this->hitPoints += healAmmount;
	}
}