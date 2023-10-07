#include <SFML/Graphics.hpp>

#include <string>
#include "player.h"
#include "enemy.h"
#include "map.h"

#include <iostream>

using namespace sf;

class Game
{
private:
    sf::RenderWindow* win;
    Player* player;
    Enemy* enemy;
    // Map* map;
    int _army_size;
    

public:
    Game(int size, std::string title, int num_spells, int army_size){
        win = new sf::RenderWindow(sf::VideoMode(size, size), title);
if (!win) {
    std::cerr << "Failed to create the window" << std::endl;
}

        // map = new Map(10, 50, 50);
        player = new Player(10, 50, 50, num_spells);
        enemy = new Enemy[army_size];
        this->_army_size = army_size;
        
    }

    void run(){
        while (win->isOpen())
        {
            Event e;
            while (win->pollEvent(e))
            {
                if (e.type == sf::Event::Closed) {
                    win->close();
                }
                // if(Keyboard::isKeyPressed(Keyboard::A)){
                //     map->move_left(6);
                // } else if (Keyboard::isKeyPressed(Keyboard::D)){
                //     map->move_right(6);
                // } else if (Keyboard::isKeyPressed(Keyboard::W)){
                //     map->move_up(6);
                // } else if (Keyboard::isKeyPressed(Keyboard::S)){
                //     map->move_down(6);
                // }
                if (Keyboard::isKeyPressed(Keyboard::E)){
                    for (int i = 0; i < _army_size; i++){
                        enemy[i].spawn(win->getSize().x-10, win->getSize().y);
                    }
                }
                
            }
            
            // map->draw(win);
            player->draw(win);
            for (int i = 0; i < _army_size; i++){
                enemy[i].draw(win);
            }
        }
        
    }
    ~Game(){
        delete this->win;
        // delete this->map;
        delete this->player;
        delete [] this->enemy;
    }
};



int main()
{
    Game game(1000, "Dog Game", 100, 10);
    game.run();
    
}
