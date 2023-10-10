#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <player.h>
#include <enemy.h>
#include <map.h>

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
    Map* map;

public:

};

#endif
