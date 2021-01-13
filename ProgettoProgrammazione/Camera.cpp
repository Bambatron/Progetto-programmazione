#include "Camera.h"

Camera::Camera(int mapWidth, int mapHeight, float width, float height, int cenX, int cenY, int nCenX, int nCenY, float speedX, float speedY): view(sf::Vector2f(cenX, cenY), sf::Vector2f(width, height))
{
	mapSize = sf::Vector2i(mapWidth, mapHeight);
	normalCenter = sf::Vector2i(nCenX, nCenY);
	maxSpeed = sf::Vector2f(speedX, speedY);
	speed = sf::Vector2f(0.0f, 0.0f);
}

void Camera::move(sf::Vector2f offset)
{
	//Check if view is ut of bound
	if (view.getCenter().x - view.getSize().x / 2 + offset.x < 0)
		offset.x = view.getCenter().x - view.getSize().x / 2;
	else if (view.getCenter().x + view.getSize().x / 2 + offset.x > mapSize.x)
		offset.x = mapSize.x - view.getCenter().x - view.getSize().x / 2;

	if (view.getCenter().y < view.getSize().y / 2)
		offset.y = view.getCenter().y - view.getSize().y / 2;
	else if (view.getCenter().y + view.getSize().y / 2 + offset.y > mapSize.y)
		offset.y = mapSize.y - view.getCenter().y - view.getSize().y / 2;;

	//Move view
	view.move(offset);
	//Update normalCenter
	normalCenter = sf::Vector2i(view.getCenter());
}

void Camera::moveView(sf::Vector2f offset)
{
	//Move view
	view.move(offset);

	//Check if view is ut of bound
	if (view.getCenter().x < view.getSize().x / 2)
		view.setCenter(view.getSize().x / 2, view.getCenter().y);
	else if (view.getCenter().x > 2400 - (view.getSize().x / 2))
		view.setCenter(2400 - (view.getSize().x / 2), view.getCenter().y);

	if (view.getCenter().y < view.getSize().y / 2)
		view.setCenter(view.getCenter().x, view.getSize().y / 2);
	else if (view.getCenter().y > 600 - (view.getSize().y / 2))
		view.setCenter(view.getCenter().x, 600 - (view.getSize().y / 2));
}

void Camera::update(float deltaTime, sf::Vector2i followed)
{
	if (fabs(followed.x - view.getCenter().x) > (view.getSize().x/2)*(60/ 100))
	{
		if (followed.x > view.getCenter().x)
			speed.x = maxSpeed.x;
		else
			speed.x = -maxSpeed.x;
	}
	else
		speed.x = 0.0f;

	if (fabs(followed.x - view.getCenter().y) > (view.getSize().y / 2)*(60 / 100))
	{
		if (followed.y > view.getCenter().y)
			speed.y = maxSpeed.y;
		else
			speed.y = -maxSpeed.y;
	}
	else
		speed.y = 0.0f;

	move(speed*deltaTime);
}
