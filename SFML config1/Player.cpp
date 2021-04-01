#include "Player.h"

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f size, float jumpHeight) :
	animation(texture, imageCount, switchTime)
{
	this->speed = speed;
	this->jumpHeight = jumpHeight;
	row = 0;
	faceRight = true;

	body.setSize(size);
	body.setPosition(20.0f, 0.0f);
	body.setTexture(texture);
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{

	velocity.x *= 0.2f;

	if (sf::Event::EventType::KeyPressed)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
			velocity.x -= speed;
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			velocity.x += speed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
		{
			canJump = false;

			velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
		}
	}


	velocity.y += 981.0f * deltaTime; //Gravite

	if (velocity.x == 0.0f)
		row = 0;
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}

	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);

}

void Player::Draw(sf::RenderWindow& window)
{

	window.draw(body);

}

void Player::Oncollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		velocity.x = 0.0f; // Left
	}
	else if (direction.x > 0.0f)
	{
		velocity.x = 0.0f; // Right
	}
	if (direction.y < 0.0f)
	{
		velocity.y = 0.0f;	// Bottom
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f; //Top
	}
}
