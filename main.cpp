#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

const sf::Keyboard::Key controls[4] = {
    sf::Keyboard::A,   // Player1 UP
    sf::Keyboard::Z,   // Player1 Down
    sf::Keyboard::Up,  // Player2 UP
    sf::Keyboard::Down, // Player2 Down
};

//Parameters
const int gameWidth = 800;
const int gameHeight = 600;
const sf::Time time_step = sf::seconds(0.017f); //60 fps
sf::Font font;
sf::Text scoreText;

//Objects of the game
sf::Texture spritesheet;
sf::Sprite invader;

void reset() {
}

void init() {
    font.loadFromFile("resources/fonts/RobotoSlab-Regular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(48);
    scoreText.setFillColor(sf::Color::White);

    if (!spritesheet.loadFromFile("resources/img/invaders_sheet.png")) {
        std::cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(32, 32)));
}

void update(float dt) {
    // handle paddle movement
    float direction = 0.0f;
    if (sf::Keyboard::isKeyPressed(controls[0])) {
        direction--;
    }
    if (sf::Keyboard::isKeyPressed(controls[1])) {
        direction++;
    }
    
}

void render(sf::RenderWindow& window) {
    // Draw Everything
    // window.draw(scoreText);
    window.draw(invader);
}

int main() {
    //create the window
    sf::RenderWindow window(sf::VideoMode({ gameWidth, gameHeight }), "Space Invaders");
    //initialise and load
    init();
    while (window.isOpen()) {
        //Calculate dt
        static sf::Clock clock;
        const float dt = clock.restart().asSeconds();

        window.clear();
        update(dt);
        render(window);
        //wait for the time_step to finish before displaying the next frame.
        sf::sleep(time_step);
        //wait for Vsync
        window.display();
    }

}