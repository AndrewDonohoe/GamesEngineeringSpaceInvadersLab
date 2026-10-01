//game_system.hpp
#include <vector>
#include <memory>
#include "ship.hpp"
#include "game_parameters.hpp"

struct GameSystem {
    //The global variables goes here
    static std::vector<std::shared_ptr<Ship>> ships; //vector of shared pointers to Ships.
    static sf::Texture spritesheet;
    static sf::Sprite invader;

    //game system functions
    static void reset();
    static void init(Parameters& p);
    static void clean();
    static void update(const float& dt);
    static void render(sf::RenderWindow& window, Parameters& p);
};