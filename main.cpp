#include <SFML/Graphics.hpp>

#include <string>
#include "game.h"
#include "player.h"
#include "enemy.h"
#include "map.h"

#include <iostream>

using namespace sf;

int main()
{
    Game game(500, "OOP Game", 100, 10);
    game.run();
    
}
