#pragma once

#include <SFML/Graphics/View.hpp>

//Interface for the sf::View class

class Camera
{
	//Attributes
private:
	sf::Vector2i mapSize;
	sf::View view;
	sf::Vector2i normalCenter;
	sf::Vector2f maxSpeed;
	sf::Vector2f speed;
	//Methods
public:
	Camera(int mapWidth = 600, int mapHeight = 600, float width = 600.0f, float height = 600.f, int cenX = 300, int cenY = 300, int nCenX = 300, int nCenY = 300, float speedX = 60.0f, float speedY = 0.0f);
	//Getters
	sf::Vector2i getViewCenter() { return sf::Vector2i(view.getCenter().x, view.getCenter().y); }
	sf::Vector2f getSize() { return view.getSize(); }
	float getRotation() { return view.getRotation(); }
	const sf::FloatRect getViewport() { return view.getViewport(); }
	const sf::View getView() { return view; }
	sf::Vector2i getNormalCenter() { return normalCenter; }
	//Setters
	void setMapSize(sf::Vector2i mapSize) { this->mapSize = mapSize; }
	void setCenter(sf::Vector2i cen) { view.setCenter(cen.x, cen.y); }
	void setSize(sf::Vector2f size) { view.setSize(size); }
	void setRotation(float angle) { view.setRotation(angle); }
	void setViewport(sf::FloatRect port) { view.setViewport(port); }
	void setViewport(sf::Vector2i pos, sf::Vector2f size) { view.setViewport(sf::FloatRect(pos.x, pos.y, size.x, size.y)); }
	void setViewport(float posX = 0, float posY = 0, float width = 1, float height = 1) { view.setViewport(sf::FloatRect(posX, posY, width, height)); }
	void setNormalCenter(sf::Vector2i nCen) { normalCenter = nCen; }
	//Transformers
	void move(sf::Vector2f offset);
	void move(float offsetX, float offsetY) { move(sf::Vector2f(offsetX, offsetY)); }
	void moveView(sf::Vector2f offset);
	void moveView(float offsetX, float offsetY) { moveView(sf::Vector2f(offsetX, offsetY)); }
	void rotate(float angle) { view.rotate(angle); }
	void zoom(float factor) { view.zoom(factor); }
	//Updates
	void update(float deltaTime, sf::Vector2i followed);
};

