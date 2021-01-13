#include "Player.h"

Player::Player()
{
	score = 0;

	for (unsigned int i = 0; i < NINPUTS; i++)
	{
		inputs[i] = false;
	}
	hp = 100;
	currentState = standing;
	facingRight = true;

	type = EntityType::player;

	hitBox.left = 140;
	hitBox.top = 200;
	hitBox.width = 20.0f;
	hitBox.height = 40.0f;
	maxSpeed.x = 100.0f;
	maxSpeed.y = 50.0f;
	speed = sf::Vector2f(0.0f, 0.0f);
	lastMovement = sf::Vector2f(0.0f, 0.0f);
	physical = true;
	kinematic = false;
	onGround = true;
	pushLeftWall = false;
	pushRightWall = false;
	atCeiling = false;
	moved = false;
	collided = false;

	sprite.setPosition(140, 200);
	sprite.setSize(sf::Vector2f(20.0f, 40.0f));
	textureID = 0;
	sprite.setFillColor(sf::Color::Red);
	sprite.setOutlineColor(sf::Color::Black);
	sprite.setOutlineThickness(1.0f);
}

Player::~Player()
{

}

bool Player::processInput(sf::Event input)
{
	bool pressed;
	if (input.type == sf::Event::KeyPressed)
		pressed = true;
	else if (input.type == sf::Event::KeyReleased)
		pressed = false;

	bool result = false;

	switch (input.key.code)
	{
	case sf::Keyboard::D:	
		inputs[goRight] = pressed;
		result = true;
		break;
	case sf::Keyboard::A:
		inputs[goLeft] = pressed;
		result = true;
		break;
	case sf::Keyboard::W:
		inputs[jump] = pressed;
		result = true;
		break;
	case sf::Keyboard::S:
		inputs[crouch] = pressed;
		result = true;
		break;
	case sf::Keyboard::K:
		inputs[KeyInput::shoot] = pressed;
		result = true;
		break;
	case sf::Keyboard::L: 
		inputs[use] = pressed;
		result = true;
		break;
	default:
		result = false;
		break;
	}
	
	return result;
}

void Player::shoot()
{
}

void Player::ability()
{
}
