#pragma once //insure that this header file is included only once and there will no multiple definition of the same thing
#include <SFML/Graphics.hpp>

struct Parameters {
    //Parameters
    static constexpr int rows = 4;
    static constexpr int columns = 30;
    static constexpr int game_width = 800;
    static constexpr int game_height = 600;
    static constexpr int sprite_size = 32;
    static constexpr float player_speed = 100.f;
    sf::Time time_step = sf::seconds(0.017f); //60 fps

    static constexpr sf::Keyboard::Key controls[2] = {
        sf::Keyboard::A, //Left
        sf::Keyboard::D, //Right
    };
};