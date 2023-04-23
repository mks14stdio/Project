
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Sprite");
    sf::Texture texture;
    
    if (!texture.loadFromFile("./sprite.png")) {
        std::cout << "Error cant load Texture!\n";
        return -1;
    }
    
    sf::Sprite sprite(texture);
    sprite.setPosition(sf::Vector2f(800 / 2, 600 / 3));
    sprite.setScale(sf::Vector2f(5.f, 5.f));
    sprite.setOrigin(8, 8);

    bool isDrag = false;

    

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i mpos = sf::Mouse::getPosition(window);
                    if (sprite.getGlobalBounds().contains(mpos.x, mpos.y)) {
                        isDrag = true;
                    }
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                isDrag = false;
            }
        }
        
        if (isDrag) {
            sprite.setPosition(static_cast<sf::Vector2f>(sf::Mouse::getPosition(window)));
        }


        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}

