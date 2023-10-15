#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "enemy.h"
#include "map.h"
#include "player.h"
#include "character.h"
#include "entity.h"
#include "ranger.h"
int main() {
  sf::RenderWindow window(sf::VideoMode(1300, 732), "Dog Thief");
  sf::Clock clock;
  sf::Time elapsedTime;
  sf::View view;
  window.setView(view);
  bool inCombat = false;
  Enemy* enemyInProximity = nullptr;
  sf::Sprite combatTextBox;


//Set background
  sf::Texture backgroundTexture;
  backgroundTexture.loadFromFile("images/GameMap1.png");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

//Create Player
  Ranger player1;

  //Create Enemy
  Enemy enemy1("Sprites/orc savage/OrcSavageIdleSide.gif", 1200, 280, 50, 50, 5);
  Enemy enemy2("Sprites/orc savage/OrcSavageIdleSide.gif", 1700, 280, 50, 50, 5);
  Enemy boss1("Sprites/orc juggernaut/OrcJuggernautIdleSide.gif", 650, 700, 50, 50, 5);
//Game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }

      // Combat check and handling
        if (!inCombat) {
            // Check for proximity to an enemy
            if (enemy1.isInProximityToPlayer(player1.get_x(), player1.get_y(), player1.get_depth()) == true && enemy1.isAlive() == true) {
               enemyInProximity = &enemy1;
            } else if (enemy2.isInProximityToPlayer(player1.get_x(), player1.get_y(), player1.get_depth()) && enemy2.isAlive()) {
               enemyInProximity = &enemy2;
            } else if (boss1.isInProximityToPlayer(player1.get_x(), player1.get_y(), player1.get_depth()) && boss1.isAlive()) {
                enemyInProximity = &boss1;
            }

            //debug stuff
if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
            inCombat = true;
}
            if (enemyInProximity) {
              inCombat = true;
            // You can add combat initialization logic here
            std::cout << "A battle has begun \n";
            bool playerTurn = true;
            }
        } else {
            // Handle combat logic here
            bool playerTurn = true;
            while(enemyInProximity->get_Health() > 0){
              std::cout << "You: \n" << "Health: " << player1.get_Health() << "/" << player1.get_maxHealth();
              std::cout << "\n Enemy: \n" << "Health: " << enemyInProximity->get_Health() << "/" << enemyInProximity->get_maxHealth() << "\n";
              if (playerTurn == true){
                std::cout << "Select attack1, attack2 or attack3\n";
                int moveChosen;
                std::cin >> moveChosen;
                if (moveChosen == 1){
                  player1.stab(enemyInProximity);
                }else if (moveChosen == 2){
                  player1.volley(enemyInProximity);
                }else if(moveChosen == 3){
                  player1.survivalSkills();
                }
                playerTurn = false;
              }else{
                player1.takeDamage(enemyInProximity->get_damage());
                playerTurn = true;
              }
            }
            enemyInProximity->die();
            enemyInProximity = nullptr;
            inCombat = false;            
            std::cout << "You won! \n";
        }

// Player movement (Only allowed when not in combat)
if (!inCombat) {
    elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() > 0.1) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player1.move_left(12);
            std::cout << "Left" << std::endl;
            clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player1.move_right(12);
            std::cout << "Right" << std::endl;
            clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player1.move_up(12);
            std::cout << "Up" << std::endl;
            clock.restart();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player1.move_down(12);
            std::cout << "Down" << std::endl;
            clock.restart();
        }
    }
}

    }

  // Update the view to follow the player
  view.setCenter(player1.get_EntityPosition());

  // Set the view's size to control the area visible on the screen
  view.setSize(sf::Vector2f(800, 450)); 

  // Apply the view to the window
  window.setView(view);
  // Create chest entity
  //Clear and Draw window
    window.clear();
    window.draw(background);
    if(enemy1.isAlive() == true){
      enemy1.draw(&window);
    }else{
      
    }
    if(enemy2.isAlive() == true){
      enemy2.draw(&window);
    }
    if(boss1.isAlive() == true){
      boss1.draw(&window);
    }
    player1.draw(&window);
    
    //Combat ui
    if (inCombat){
      sf::Texture combatTexture;
      combatTexture.loadFromFile("images/Textbox.png");
      sf::Sprite combatTextBox(combatTexture);
      combatTextBox.setPosition(view.getCenter().x - combatTextBox.getGlobalBounds().width / 4, view.getCenter().y + 90);
      combatTextBox.setScale(0.5,0.5);
      window.draw(combatTextBox);
    }

    window.display();
  }

  return 0;
}