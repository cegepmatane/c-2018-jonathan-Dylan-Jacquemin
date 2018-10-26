#pragma once

#include "Weapon.h"

using namespace std;

class Staff : public Weapon {
	public:
		Staff();
		Staff(int);
		virtual ~Staff();

		// methods
		void initProp();
		void giveWeaponSpecifications();
		std::string exportDatas();
		int operator+(Weapon&);
};
