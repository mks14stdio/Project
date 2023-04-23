#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Circle!");
    sf::CircleShape shape(32.f);
    shape.setFillColor(sf::Color::Blue);
    shape.setPosition(sf::Vector2f(800 / 2, 600 / 2));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        float moveX = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        float moveY = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
        shape.move(sf::Vector2f(moveX, moveY));

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}