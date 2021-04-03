#include "Platforme.h"


Platforme::Platforme(sf::Texture* texture, sf::Vector2f size, sf::Vector2f position,unsigned int layer)
{
	body.setSize(size);
	body.setOrigin(size * 0.5f);
	body.setTexture(texture);
	body.setPosition(position);	
	this->layer = layer;
}

Platforme::~Platforme()
{
}

void Platforme::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
