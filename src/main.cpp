#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                window.clear(sf::Color::Black);
                window.draw(shape);
                window.display();
            }

            if (event.type == sf::Event::KeyReleased) {
                window.clear(sf::Color::Black);
                window.display();
            }
        }

    }

    return 0;
}