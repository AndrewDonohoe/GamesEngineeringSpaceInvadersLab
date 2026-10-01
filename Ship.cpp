//ship.cpp
#include "ship.hpp"
#include "game_parameters.hpp"
#include "game_system.hpp"

using p = Parameters;
using gs = GameSystem;

Ship::Ship() {};

Ship::Ship(const Ship& s) :
	_sprite(s._sprite) {
}

Ship::Ship(sf::IntRect ir, sf::Texture& spritesheet) : Sprite() {
	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);
};

void Ship::update(const float& dt) {}

void Ship::move_down() {}

//Define the ship deconstructor. 
//Although we set this to pure virtual, we still have to define it.
Ship::~Ship() = default;


//Invader
Invader::Invader() : Ship() {}
Invader::Invader(const Invader& inv) : Ship(inv) {}
Invader::Invader(sf::IntRect ir, sf::Vector2f pos, sf::Texture& spritesheet) : Ship(ir, spritesheet) {
	setOrigin(sf::Vector2f(16.f, 16.f));;
	setPosition(pos);
}

bool Invader::direction;
float Invader::speed;
float Invader::acc;

void Invader::update(const float& dt) {
	Ship::update(dt);

	move(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f);

	if ((direction && getPosition().x > p::game_width - p::sprite_size / 2.f) ||
		(!direction && getPosition().x < p::sprite_size / 2.f)) {
		direction = !direction;
		speed += Invader::acc;
		for (std::shared_ptr<Ship>& ship : gs::ships) {
			ship->move_down();
		}
	}
}

void Invader::move_down() {
	move(sf::Vector2f(0.f, 10.f));
}

Player::Player() :
	Ship(sf::IntRect(sf::Vector2i(p::sprite_size * 5, p::sprite_size),
		sf::Vector2i(p::sprite_size, p::sprite_size)), gs::spritesheet) {
	setOrigin(p::sprite_size / 2.f, p::sprite_size / 2.f);
	setPosition(p::game_width / 2.f, p::game_height - static_cast<float>(p::sprite_size));
}

void Player::update(const float& dt) {
	Ship::update(dt);
	float direction = 0.0f;
	//Move Left
	if (sf::Keyboard::isKeyPressed(p::controls[0])) {
		direction--;
	}
	//Move Right
	if (sf::Keyboard::isKeyPressed(p::controls[1])) {
		direction++;
	}
	move(sf::Vector2f(direction * p::player_speed * dt, 0.f));
}