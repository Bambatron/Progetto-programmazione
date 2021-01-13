#include "CollisionData.h"

CollisionData::CollisionData(CollisionType type, sf::FloatRect overlap, Entity * obj1, Entity * obj2)
{
	this->type = type;
	this->overlap = overlap;
	if (obj1->getType() <= obj2->getType())
	{
		this->obj1 = obj1;
		this->obj2 = obj2;
	}
	else
	{
		this->obj1 = obj2;
		this->obj2 = obj1;
	}
}

bool CollisionData::doesCollide(EntityType type1, EntityType type2)
{
	if (type1 > type2)
	{
		EntityType tmp = type2;
		type2 = type1;
		type1 = tmp;
	}

	if (type1 == platform)
	{
		if (type2 == destroyable)
			return true;
		else if (type2 == bullet)
			return true;
		else if (type2 == alien || type2 == player)
			return true;
		else if (type2 == drop)
			return true;
		else
			return false;
	}

	if (type1 == movingPlatform)
	{
		if (type2 == destroyable)
			return true;
		else if (type2 == bullet)
			return true;
		else if (type2 == alien || type2 == player)
			return true;
		else if (type2 == drop)
			return true;
		else
			return false;
	}

	if (type1 == destroyable)
	{
		if (type2 == destroyable)
			return true;
		else if (type2 == bullet)
			return true;
		else if (type2 == alien || type2 == player)
			return true;
		else if (type2 == drop)
			return true;
		else
			return false;
	}

	if (type1 == bullet)
	{
		if (type2 == alien || type2 == player)
			return true;
		else 
			return false;
	}

	if (type1 == alien)
	{
		if (type2 == alien || type2 == player)
			return true;
		else
			return false;
	}

	if (type1 == player && type2 == drop)
		return true;
	else
		return false;
}

bool CollisionData::doesCollide(EntityType type1, EntityType type2, CollisionType * type)
{
	if (type1 > type2)
	{
		EntityType tmp = type2;
		type2 = type1;
		type1 = tmp;
	}

	if (type1 == platform)
	{
		if (type2 == destroyable)
		{
			*type = destrToPlat;
			return true;
		}
		else if (type2 == bullet)
		{
			*type = bullToPlat;
			return true;
		}
		else if (type2 == alien || type2 == player)
		{
			*type = charToPlat;
			return true;
		}
		else if (type2 == drop)
		{
			*type = dropToPlat;
			return true;
		}
		else
		{
			*type = null;
			return false;
		}
	}

	if (type1 == movingPlatform)
	{
		if (type2 == destroyable)
		{
			*type = movPlatToDestr;
			return true;
		}
		else if (type2 == bullet)
		{
			*type = movPlatToBull;
			return true;
		}
		else if (type2 == alien || type2 == player)
		{
			*type = movPlatToChar;
			return true;
		}
		else if (type2 == drop)
		{
			*type = movPlatToDrop;
			return true;
		}
		else
		{
			*type = null;
			return false;
		}
	}

	if (type1 == destroyable)
	{
		if (type2 == destroyable)
		{
			*type = destrToDestr;
				return true;
		}
		else if (type2 == bullet)
		{
			*type = destrToBull;
			return true;
		}
		else if (type2 == alien || type2 == player)
		{
			*type = destrToChar;
			return true;
		}
		else if (type2 == drop)
		{
			*type = destrToDrop;
			return true;
		}
		else
		{
			*type = null;
			return false;
		}
	}

	if (type1 == bullet)
	{
		if (type2 == alien || type2 == player)
		{
			*type = bullToChar;
			return true;
		}
		else
		{
			*type = null;
			return false;
		}
	}

	if (type1 == alien)
	{
		if (type2 == alien)
		{
			*type = aliToAli;
			return true;
		}
		else if (type2 == player)
		{
			*type = aliToPlay;
			return true;
		}
		else
		{
			*type = null;
			return false;
		}
	}

	if (type1 == player && type2 == drop)
	{
		*type = playToDrop;
		return true;
	}
	else
	{
		*type = null;
		return false;
	}
}
