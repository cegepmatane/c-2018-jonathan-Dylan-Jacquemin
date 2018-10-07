/*
 * Bow.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef BOW_H_
#define BOW_H_

#include "Weapon.h"

namespace std {

class Bow : public Weapon{
public:
	Bow();
	Bow(int);
	virtual ~Bow();
	// methods
	void giveWeaponSpecifications();
	string exportDatas();
};

} /* namespace std */

#endif /* BOW_H_ */
