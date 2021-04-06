#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <tgmath.h>
#include "Animation.h"
#include "Collider.h"
#include "inventory.h"
#include "Rigidbody.h"

class Equipe
{
public:
	Equipe(int tagEquipe);
	~Equipe();


	inventory* GetInventaire() { return &inventaire; }
	int* GetTagEquipe() { return &tagEquipe; }

private:
	inventory inventaire;
	int tagEquipe;
};



class Player : public Rigidbody
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, sf::Vector2f size, sf::Vector2f spawnPoint ,float jumpHeight, int maxLife, Equipe* equipe);
	~Player();


	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window) { window.draw(body); };
	void Oncollision(sf::Vector2f direction);

	void SetMovement(bool state) { canMove = state; };
	void RecoverLife(int amount);
	

	int* GetLife() { return &life; }
	bool IsFaceRight() { return faceRight; }
	bool TakeDamage(int damage);
	bool Shoot(std::string type);
	int GetMunition(std::string type);
	int* GetTagEquipe() { return equipe->GetTagEquipe(); }
	Equipe* GetEquipe() { return equipe; }

private:
	sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	float speed;
	bool faceRight;

	sf::Vector2f velocity;
	bool canJump = true;
	float jumpHeight;
	bool canMove = false;

	int life;
	int maxLife = 100;

	Equipe* equipe;

};