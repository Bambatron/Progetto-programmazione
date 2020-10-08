#include "Drawable.h"
void Drawable::initTexture()
{
	//Load a texture from file
	if (this->texture.loadFromFile("Texture/image.png"))
	{
		std::cout << "ERROR::DRAWABLE::INITTEXTURE::Could not load texture from file." << "\n";
	}
}
void Drawable::initSprite(float scale)
{
	//Set the texture to the sprite
	this->sprite.setTexture(this->texture);

	//Resize the sprite
	this->sprite.scale(xf, xf);
}
Drawable::Drawable()
{
	this->initTexture();
	this->initSprite(25.f);
}