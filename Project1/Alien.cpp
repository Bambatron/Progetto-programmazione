#include "Alien.h"

void Alien::initVariables()
{

}
void Alien::initAnimations()
{

	//this->animationComponent->addAnimation("IDLE",x.f,0,0,a,0,b,b);
	//this->animationComponent->addAnimation("WALK_DOWN",x.f,0,a,c,a,b,b);
	//this->animationComponent->addAnimation("WALK_LEFT",x.f,d,a,c,a,b,b);
	//this->animationComponent->addAnimation("WALK_RIGHT",x.f,d,a,c,a,b,b);
	//this->animationComponent->addAnimation("WALK_UP",x.f,d,a,c,a,b,b);
	//this->animationComponent->addAnimation("ATTACK",x.f,0,a,c,a,b,b);

}
void Alien::initTexture()
{
	//Load a texture from file
	if (!this->textureSheet.loadFromFile("Texture/player_sheet.png"))
	{
		std::cout << "ERROR::PLAYER::Could not load the player sheet!" << "\n";
	}
}

void Alien::initSprite()
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame = sf::IntRect(0, 0, x, x);// Serve a dire quale porzione della Sprite si deve muovere(x sarà 32 e 64 circa)
	this->sprite.setTexturerRect(this->currentFrame);

	//Resize the sprite
	this->sprite.scale(xf, xf);
}

Alien::Alien(float x, float y, sf::Texture& texture_sheet)
{

	this->initVariables();


	//this->createHitboxComponent(this->sprite, 0.f, 0.f, sprite.getGlobalBounds().widht, sprite.getGlobalBounds().height);
	//this->createMovementComponent(x.f, y.f, z.f);
	//this->createAnimationComponent(texture_sheet);

	this->setPosition(x, y);
	//this->initAnimation();

}
}
Alien::~Alien()
{

}
void Alien::update(const float& dt, sf::Vector2f& mouse_pos_view)
{
	//this->movementComponent->update(dt);

	//this->updateAttack(); //NO

	//this->updateAnimation(dt); //NO

	//this->hitboxComopnent->update();


}
void Alien::render(sf::RenderTarget & target, const bool show_hitbox)
{
	if
	{
		target.draw(this->sprite);
	}
	else
	{
		target.draw(this->sprite);
	}
	if (show_hitbox)
		this->hitboxComponent->render(target);
}
















// vediamo se lasciarlo
const sf::FloatRect Alien::getBounds() const
{
	return this->shape.getGlobalBounds();
}

const int & Alien::getPoints() const
{
	return this->points ;
}
const int & Alien::getDamage() const
{
	return this->damage;
}

//Functions
void Alien::update();
{
	this->shape.move(0.f, this->speed);
}
void Alien::render(sf::RenderTarget*target);
{
	target->draw(this->shape);

}

