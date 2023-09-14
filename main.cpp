#include <SFML/Graphics.hpp>

int main()
{
    float windowHeight = 400;
    float windowWidth = 400;

    sf::RenderWindow window(sf::VideoMode(windowWidth,windowHeight), "RPG");


    sf::Texture texture;
    if(!texture.loadFromFile("images/enemy.png")){
        return 0;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);

    while (window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
    
}