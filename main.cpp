#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "game_parameters.hpp"
#include "game_system.hpp"

int main() {
    Parameters p;

    //create the window
    sf::RenderWindow window(sf::VideoMode({ p.game_width, p.game_height }), "Space Invaders");
    //initialise and load
    GameSystem::init(p);
    while (window.isOpen()) {
        //Calculate dt
        static sf::Clock clock;
        const float dt = clock.restart().asSeconds();

        window.clear();
        GameSystem::update(dt);
        GameSystem::render(window, p);
        //wait for the time_step to finish before displaying the next frame.
        sf::sleep(p.time_step);
        //wait for Vsync
        window.display();
    }

}