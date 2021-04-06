#include "Missile.h"


#define PI 3.1416

Missile::Missile(sf::Texture* texture, sf::Vector2f size, sf::Vector2f spawnPoint, float radiusExplo ,sf::Vector2f angle, float power, int damage) :
	Rigidbody(&body)
{
	this->power = power;
	this->angle = angle;
	this->damage = damage;

	body.setSize(size);
	body.setTexture(texture);
	body.setOrigin(size * 0.5f);
	body.setPosition(spawnPoint);
	body.setRotation(90);

	explosion.setRadius(radiusExplo);
	explosion.setOrigin(sf::Vector2f(radiusExplo, radiusExplo));
	explosion.setPosition(spawnPoint);
	
}

Missile::~Missile()
{
}

void Missile::Update(float deltaTime)
{
	velocity += angle * power;
	power = 0;
	velocity.y += 981.0f * deltaTime; //Gravite
	body.move(velocity * deltaTime);

	body.setRotation(90.0f + Math::GetAngleVector(velocity));
	explosion.setPosition(body.getPosition());
}

void Missile::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}

void Missile::DrawExplosion(sf::RenderWindow& window)
{
	window.draw(explosion);
}

