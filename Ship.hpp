//ship.hpp
#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite {
public:
    Ship();
    //Copy constructor
    Ship(const Ship& s);
    //Constructor that takes a sprite
    Ship(sf::IntRect ir, sf::Texture& spritesheet);
    //Pure virtual deconstructor -- makes this an abstract class and avoids undefined behaviour!
    virtual ~Ship() = 0;
    //Update, virtual so can be overridden, but not pure virtual
    virtual void update(const float& dt);
    virtual void move_down();
protected:
    sf::IntRect _sprite;

};

class Invader : public Ship {
public:
    static bool direction;
    static float speed;
    static float acc;

    Invader();
    Invader(const Invader& inv);
    Invader(sf::IntRect ir, sf::Vector2f pos, sf::Texture& spritesheet);
    void update(const float& dt) override;
    virtual void move_down() override;

};

class Player : public Ship {
public:
    Player();
    void update(const float& dt) override;
};