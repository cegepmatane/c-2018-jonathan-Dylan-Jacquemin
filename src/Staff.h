/*
 * Staff.h
 *
 *  Created on: 28 sept. 2018
 *      Author: DYLAN-MSI
 */

#ifndef STAFF_H_
#define STAFF_H_

#include "Weapon.h"

namespace std {

class Staff : public Weapon {
public:
	Staff();
	virtual ~Staff();
	// methods
	void giveWeaponSpecifications();
	void exportDatas();
};

} /* namespace std */

#endif /* STAFF_H_ */
