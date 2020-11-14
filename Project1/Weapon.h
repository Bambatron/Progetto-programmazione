#pragma once
#include <math.h>
#include "Item.h"
class Weapon
	public Item
{
private:
	int damageMax;
	int damageMin;


public:
	Weapon();

	int damageMax;
	int damageMin;
	std::string name;
	unsigned type;

	virtual ~Weapon();

	inline const int& getDamageMax() const { return this->damageMax; }
	inline const int& getDamageMin() const { return this->damageMin; }

};



