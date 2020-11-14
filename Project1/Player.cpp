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
	if (!this->textureSheet.loadFromFile("Texture/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0,0,x,x);// Serve a dire quale porzione della Sprite si deve muovere(x sarà 32 e 64 circa)
	this->sprite.setTexturerRect(this->currentFrame);

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

void Player::updateMovement()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-x.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(x.f, 0.f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->sprite.move(0.f, -x.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, x.f);
	}

}

void Player::updateAttack()
{
	if (this->attackNotHit < this->attackNotHitMax)
		this->attackNotHit += 0, xf;

}
void Player::update()
{
	this->updateMovement();
}
void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}














