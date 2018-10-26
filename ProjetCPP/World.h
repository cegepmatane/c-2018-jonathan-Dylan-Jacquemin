#pragma once

#include <vector>
#include <iostream>

#include "Character.h"
#include "Archer.h"
#include "Mage.h"
#include "Priestess.h"

#include "Weapon.h"
#include "Bow.h"
#include "Spell.h"
#include "Staff.h"

using namespace std;

class World {
	public:
		World();
		~World();
		//attributes
		std::vector<Weapon*> weaponsList;
		std::vector<Character*> charactersList;
		Character* currentCharacter;
		int playingCharacterNumber;
		int gameTurn;
		//methods
		void nextCharacter();
		void save();
};
