#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed   = x.f;
	this->attackNotHitMax = x.f;
	this->attackNotHit = attackNotHitMax;
	this->hpMax = x;
	this->hp = this->hpMax;


}
void Player::initTexture()
{
	//Load a texture from file
	if (this->texture.loadFromFile("Texture/image.png"))
	{
		std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture from file." << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(xf, xf);
}
Player::Player()
{
	this->initVariables();
	this->initTexture();
	this->initSprite();
}
Player::~Player()
{

}

const sf::Vector2f & Player::getPos() const
{
	return this->sprite.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return this->sprite.getGlobalBounds();
}

const int & Player::getHp() const
{
	return this->hp;
}
const int & Player::getHpTot() const
{
	return this->hpTot;
}

void setPosition(const sf::Vector2f pos)
{
	this->sprite.setPosition(pos);
}
void setPosition(const float x, const float y)
{
	this->sprite.setPosition(x,y);
}
void Player::setHp(const int hp)
{
	this->hp = hp;
}
void Player::loseHp(const int value)
{
	this->hp -= value;
	if (this->hp < 0)
		this->hp = 0;
}


void Player::move(const float posX, const float posY)
{
	this->sprite.move(this->movementSpeed*posX, this->movementSpeed*posY);
}
const bool Player::camAttack()
{
	if (this->attachNotHit >= this->attackNotHit)
	{
		this->attackNotHit = 0, f;
		return true;
	}
	return false;
}
void Player::updateAttack()
{
	if (this->attackNotHit < this->attackNotHitMax)
		this->attackNotHit += 0, xf;

}
void Player::update()
{
	this->updateAttack();
}
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}














