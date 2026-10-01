#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include "game_system.hpp"
#include "game_parameters.hpp"

using gs = GameSystem;

//Objects of the game
sf::Texture gs::spritesheet;
sf::Sprite gs::invader;

std::vector<std::shared_ptr<Ship>> gs::ships;

void gs::reset() {
}

void gs::init(Parameters& p) {
    if (!spritesheet.loadFromFile("resources/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }

    Invader::speed = 30.f;
    Invader::acc = 5.f;

    for (int r = 0; r < p.rows; ++r) {
        auto rect = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32));
        for (int c = 0; c < p.columns; ++c) {
            sf::Vector2f position = sf::Vector2f{ c*20.f,r*20.f };
            std::shared_ptr<Invader> inv = std::make_shared<Invader>(rect, position, spritesheet);
            gs::ships.push_back(inv);
        }
    }

    std::shared_ptr<Player> player = std::make_shared<Player>();
    gs::ships.push_back(player);
}

void gs::update(const float& dt) {
    for (std::shared_ptr<Ship>& s : ships) {
        s->update(dt);
    }
}

void gs::render(sf::RenderWindow& window, Parameters& p) {
    // Draw Everything
    window.draw(invader);
    for (const std::shared_ptr<Ship>& s : ships) {
        window.draw(*(s.get()));
    }
}

void gs::clean() {
    for (std::shared_ptr<Ship>& ship : ships)
        ship.reset();
    ships.clear();
}