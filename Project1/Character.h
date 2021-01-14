#pragma once
#include <math.h>
#include "Entity.h"

class Character
	public Entity;
{

public:

	Character();
	virtual ~Character();


	void takeDamage();
	void returnHp();//boost Heal

	void setHp(int hp);
	void setHpMax(int hp_max);
	void setAmmo(int i);
	void setRatio(const sf::Time& ratio);

	int getHp();
	int getHpMax();
	int getAmmo();
	const sf::Time getRatio();

	bool isShooting();

	void loseHP(const int hp);
	void gainHP(const int hp);

	const bool isDead() const;

	void updateStats(const bool reset);
    void update();

protected:
	
	sf::Time reload_clock;
	sf::Time ratio_clock;

	int hp;
	int hp_max;

	int ammo;
	int ammo_max;

	bool reloading = false;
	bool shoot;
};

