#pragma once
#include <math.h>
class Weapon
	public Entity
{
public:
	Weapon();
	virtual ~Weapon();
	void setRange(float range);
	void EffectRange(int effect_range);
	void Damage(int damage);
	void setMagSize(int mag_size);
	void setActualMagSize(int actual_mag_size);

	int get();
	int getHpTot();
	int getSpeed();

protected:
	int hp;
	int hp_tot;
	int speed;

	sf::Time reload_cd;
	sf::Time reload_clock;
	sf::Time ratio_cd;
	sf::Time ratio_clock;

	bool reloading = false;
	bool shoot;
};



