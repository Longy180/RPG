#include <SFML/Graphics.hpp>

#include <string>
#include "player.h"
#include "enemy.h"

#include <iostream>

using namespace sf;

class Game
{
private:
    sf::RenderWindow* win;
    Player* player;
    Enemy* enemy;
    int _army_size;
    int _num_spells;
    int _score;
    sf::Text info;
    sf::Font font;

public:
    Game(int size, std::string title, int num_spells, int army_size){
        win = new sf::RenderWindow(sf::VideoMode(size,size),title);
        player = new Player(10, 50, 50, num_spells);
        enemy = new Enemy[army_size];
        this->_army_size = army_size;
        this->_num_spells = num_spells;
        _score = 0;
        if(!font.loadFromFile("Fonts/VideoGame_Font.ttf")){
            std::cout << "Font not Found\n";
            exit(0);
        }
        info.setFont(font);
        info.setFillColor(sf::Color::White);
        info.setCharacterSize(20);
    }

    void check_score(){
        for (int i = 0; i < _army_size; i++){
            if(enemy[i].isAlive()){
                if(enemy[i].isHit(player->get_x(), player->get_y(), player->get_depth())){
                    _score--;
                    enemy[i].die();
                    enemy[i].spawn(win->getSize().x-10, win->getSize().y);
                }
                if(player->isHit(enemy[i].get_x(), enemy[i].get_y(), enemy[i].get_depth())){
                    _score++;
                    enemy[i].die();
                    enemy[i].spawn(win->getSize().x-10, win->getSize().y);
                }
            }
        }
        
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
                if(Keyboard::isKeyPressed(Keyboard::A)){
                    player->move_left(6);
                } else if (Keyboard::isKeyPressed(Keyboard::D)){
                    player->move_right(6);
                } else if (Keyboard::isKeyPressed(Keyboard::W)){
                    player->move_up(6);
                } else if (Keyboard::isKeyPressed(Keyboard::S)){
                    player->move_down(6);
                }
                if (Keyboard::isKeyPressed(Keyboard::Space)){
                    player->fire();
                }
                if (Keyboard::isKeyPressed(Keyboard::E)){
                    for (int i = 0; i < _army_size; i++){
                        enemy[i].spawn(win->getSize().x-10, win->getSize().y);
                    }
                }
                
            }
            win->clear();
            check_score();
            if(_score < 0 ){
                break;
            }
            player->draw(win);
            for (int i = 0; i < _army_size; i++){
                enemy[i].draw(win);
            }
            std::string msg;
            msg = "Score: " + std::to_string(_score) + " ";
            info.setString(msg);
            win->draw(info);
            win->display();
            
        }
        
    }
    ~Game(){
        delete this->win;
        delete this->player;
        delete [] this->enemy;
    }
};



int main()
{
    Game game(500, "OOP Game", 100, 10);
    game.run();
    
}
