
#include "game.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "attackBoost.h"
#include "character.h"
#include "collision.h"
#include "enemy.h"
#include "entity.h"
#include "fighter.h"
#include "healthBoost.h"
#include "healthPotion.h"
#include "item.h"
#include "mage.h"
#include "map.h"
#include "player.h"
#include "ranger.h"
Game::Game()
    : window(sf::VideoMode(700, 500), "Dog Thief", sf::Style::Close),
      player1(
          (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif",
          200, 200, 100, 100, 10, 0),
      enemy1("Sprites/orc savage/OrcSavageIdleSide.gif", 1200, 280, 50, 50, 5),
      enemy2("Sprites/orc savage/OrcSavageIdleSide.gif", 1700, 280, 50, 50, 5),
      boss1("Sprites/orc juggernaut/OrcJuggernautIdleSide.gif", 650, 700, 100, 100, 8) {
  // Initialize member variables and load resources here
  if (!font.loadFromFile("Fonts/VideoGame_Font.ttf")) {
    std::cout << "error loading font\n";
  }
  text.setFont(font);
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  text.setString("Choose your class:\n1. Fighter\n2. Mage\n3. Ranger");
  text.setPosition(20.0f, 20.0f);

  combatText.setFont(font);
  combatText.setCharacterSize(24);
  combatText.setFillColor(sf::Color::White);

  shopText.setFont(font);
  shopText.setCharacterSize(24);
  shopText.setFillColor(sf::Color::White);

  playerClass = 0;
  validChoice = false;
  inCombat = false;
  inShop = false;
  enemyInProximity = nullptr;
  mapOpen = true;

  // Initialise player
  Player player1(
      (std::string) "Sprites/halfling ranger/HalflingRangerIdleSide.gif", 200,
      200, 100, 100, 10, 0);
}

void Game::runGame() {
  // Game loop
  while (window.isOpen()) {
    chooseClass();
    handleEvents();
  }
}

void Game::chooseClass() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      if (event.type == sf::Event::TextEntered) {
        if (event.text.unicode >= '1' && event.text.unicode <= '3') {
          playerClass = event.text.unicode - '0';
          validChoice = true;
        }
      }
    }

    window.clear();
    window.draw(text);
    window.display();

    if (validChoice) {
      // Based on the player's choice, set the player's class
      switch (playerClass) {
        case 1:  // Fighter
          std::cout << "You chose Fighter." << std::endl;
          // Create Player
          player1 = Fighter();
          combatText.setString(
              "Your Turn:\n1. Tackle\n2. Takedown\n3. Recover");
          break;
        case 2:  // Mage
          std::cout << "You chose Mage." << std::endl;
          // Create Player
          player1 = Mage();
          combatText.setString(
              "Your Turn:\n1. Cast Fireball\n2. Summon Lightning\n3. Meditate");
          break;
        case 3:  // Ranger
          std::cout << "You chose Ranger." << std::endl;
          // Create Player
          player1 = Ranger();
          combatText.setString(
              "Your Turn:\n1. Stab\n2. Volley\n3. Survival Skills");
          break;
        default:
          // Handle invalid choice
          std::cout << "Invalid choice. Please choose 1, 2, or 3." << std::endl;
      }
      break;
    }
  }

  window.setView(view);

  // Initiate player turn and move chosen
  playerTurn = true;
}

<<<<<<< HEAD
void Game::movement(){
    if (!inCombat) {
        elapsedTime = clock.getElapsedTime();
        if (elapsedTime.asSeconds() > 0.1) {
          // Attempting to move LEFT
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
              sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            if (mapCollision.willHit(player1) == false) {
              player1.move_left(12);
              std::cout << "Left" << std::endl;
            }
            if (mapCollision.willHit(player1) == true) {
              player1.move_right(12);
              std::cout << "Moving right from collision" << std::endl;
            }
            clock.restart();

            // Attempting to move RIGHT
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            if (mapCollision.willHit(player1) == false) {
              player1.move_right(12);
              std::cout << "Right" << std::endl;
            }
            if (mapCollision.willHit(player1) == true) {
              player1.move_left(12);
              std::cout << "Moving left from collision" << std::endl;
            }
            clock.restart();

            // Attempting to move UP
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            if (mapCollision.willHit(player1) == false) {
              player1.move_up(12);
              std::cout << "Up" << std::endl;
            }
            if (mapCollision.willHit(player1) == true) {
              player1.move_down(12);
              std::cout << "Moving down from collision" << std::endl;
            }
            clock.restart();

            // Attempting to move DOWN
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            if (mapCollision.willHit(player1) == false) {
              player1.move_down(12);
              std::cout << "Down" << std::endl;
            }
            if (mapCollision.willHit(player1) == true) {
              player1.move_up(12);
              std::cout << "Moving up from collision" << std::endl;
            }
            clock.restart();
          }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        //Shop logic
        int purchaseChoice = 0;
        inShop = true;
        shopText.setString(
              "Welcome to the shop\n");
        std::cout << "Welcome to the shop\n";
        while(purchaseChoice != 4){
        std::cout << "You have: " << player1.get_Gold() << " Gold.\n"
        << "To purchase a Tough Ring for 10 gold press  1.\n"
        << "To purchase a Tenacity Ring for 10 gold press 2.\n"
        << "To purchase a Health Potion for 10 gold press 3.\n"
        << "To exit the shop press 4.\n";
        std::cin >> purchaseChoice;
        if (purchaseChoice == 1){
          AttackBoost* toughRing = new AttackBoost();
          if(player1.get_Gold() < toughRing ->get_buyPrice()){
            std::cout << "You do not have enough gold.\n";
          }else{
            player1.addToInventory(toughRing);
            player1.add_Gold(-10);
            std::cout << "You received a Tough Ring ! \n";
            toughRing->itemEffect(&player1);
            std::cout << "Your damage has increased by 3! \n";
          }
        } else if(purchaseChoice == 2){
          HealthBoost* tenacityRing = new HealthBoost();
          if(player1.get_Gold() < tenacityRing ->get_buyPrice()){
            std::cout << "You do not have enough gold.\n";
          }else{
            player1.addToInventory(tenacityRing);
            player1.add_Gold(-10);
            std::cout << "You received a Tenacity Ring ! \n";
            tenacityRing->itemEffect(&player1);
            std::cout << "Your max health has increased by 25! \n";
          }
        }else if(purchaseChoice == 3){
          HealthPotion* smallPotion = new HealthPotion();
          if(player1.get_Gold() < smallPotion ->get_buyPrice()){
            std::cout << "You do not have enough gold.\n";
          }else{
            player1.addToInventory(smallPotion);
            player1.add_Gold(-10);
            std::cout << "You received a Health Potion! \n";
            std::cout << "Open your inventory to use an item. \n";
          }
        }else if (purchaseChoice == 4){
          inShop == false;
        }
=======
void Game::movement() {
  if (!inCombat) {
    elapsedTime = clock.getElapsedTime();
    if (elapsedTime.asSeconds() > 0.1) {
      // Attempting to move LEFT
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (mapCollision.willHit(player1) == false) {
          player1.move_left(12);
          std::cout << "Left" << std::endl;
        }
        if (mapCollision.willHit(player1) == true) {
          player1.move_right(12);
          std::cout << "Moving right from collision" << std::endl;
>>>>>>> 93bee04dd640b7cf53a7b6a602fccfa41fcf71a4
        }
        clock.restart();
<<<<<<< HEAD
          }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)){
            std::cout << "Inventory: \n";
=======

        // Attempting to move RIGHT
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        if (mapCollision.willHit(player1) == false) {
          player1.move_right(12);
          std::cout << "Right" << std::endl;
        }
        if (mapCollision.willHit(player1) == true) {
          player1.move_left(12);
          std::cout << "Moving left from collision" << std::endl;
        }
        clock.restart();

        // Attempting to move UP
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (mapCollision.willHit(player1) == false) {
          player1.move_up(12);
          std::cout << "Up" << std::endl;
        }
        if (mapCollision.willHit(player1) == true) {
          player1.move_down(12);
          std::cout << "Moving down from collision" << std::endl;
        }
        clock.restart();

        // Attempting to move DOWN
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) ||
                 sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (mapCollision.willHit(player1) == false) {
          player1.move_down(12);
          std::cout << "Down" << std::endl;
        }
        if (mapCollision.willHit(player1) == true) {
          player1.move_up(12);
          std::cout << "Moving up from collision" << std::endl;
        }
        clock.restart();




      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
        // Shop logic
        inShop = true;
        shopText.setString("Welcome to the shop\n");
        render();
        window.display();
        std::cout << "Welcome to the shop\n";
        while (inShop == true) {
          std::cout << "You have: " << player1.get_Gold() << " Gold.\n"
                    << "To purchase a Tough Ring for 10 gold press  1.\n"
                    << "To purchase a Tenacity Ring for 10 gold press 2.\n"
                    << "To purchase a Health Potion for 10 gold press 3.\n"
                    << "To exit the shop press 4.\n";
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            AttackBoost* toughRing = new AttackBoost();
            if (player1.get_Gold() < toughRing->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
            } else {
              player1.addToInventory(toughRing);
              player1.add_Gold(-10);
              std::cout << "You received a Tough Ring ! \n";
              toughRing->itemEffect(&player1);
              std::cout << "Your damage has increased by 3! \n";
            }
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            HealthBoost* tenacityRing = new HealthBoost();
            if (player1.get_Gold() < tenacityRing->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
            } else {
              player1.addToInventory(tenacityRing);
              player1.add_Gold(-10);
              std::cout << "You received a Tenacity Ring ! \n";
              tenacityRing->itemEffect(&player1);
              std::cout << "Your max health has increased by 25! \n";
            }
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
            HealthPotion* smallPotion = new HealthPotion();
            if (player1.get_Gold() < smallPotion->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
            } else {
              player1.addToInventory(smallPotion);
              player1.add_Gold(-10);
              std::cout << "You received a Health Potion! \n";
              std::cout << "Open your inventory to use an item. \n";
            }
          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
            inShop = false;
          }
        }




        clock.restart();
      } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
        std::cout << "Inventory: \n";
      }
    }
  }
}






void Game::combat() {
  playerTurn = true;
  bool playerHasChosen = false;
  playerHealthText.setFont(font);
  playerHealthText.setCharacterSize(12);
  playerHealthText.setFillColor(sf::Color::White);
  playerHealthText.setString("Health: " + std::to_string(player1.get_Health()) +
                             "/100");
  playerHealthText.setPosition(player1.get_EntityPosition().x,
                               player1.get_EntityPosition().y);
  window.draw(playerHealthText);

  enemyHealthText.setFont(font);
  enemyHealthText.setCharacterSize(12);
  enemyHealthText.setFillColor(sf::Color::White);
  enemyHealthText.setString(
      "Health: " + std::to_string(enemyInProximity->get_Health()) + "/100");
  enemyHealthText.setPosition(enemyInProximity->get_EntityPosition().x,
                              enemyInProximity->get_EntityPosition().y - 20);
  window.draw(enemyHealthText);

  window.display();

  while (enemyInProximity->get_Health() > 0) {
    if (playerTurn == true) {
      playerHasChosen = false;

      sf::Event event;
      while (window.pollEvent(event) && !playerHasChosen) {
        if (event.type == sf::Event::TextEntered) {
          if (event.text.unicode >= '1' && event.text.unicode <= '3') {
            int moveChosen = event.text.unicode - '0';
            if (moveChosen == 1) {
              player1.attack1(enemyInProximity);
            } else if (moveChosen == 2) {
              player1.attack2(enemyInProximity);
            } else if (moveChosen == 3) {
              player1.heal();
            }
            std::cout << "You: \n"
                      << "Health: " << player1.get_Health() << "/"
                      << player1.get_maxHealth();
            std::cout << "\n Enemy: \n"
                      << "Health: " << enemyInProximity->get_Health() << "/"
                      << enemyInProximity->get_maxHealth() << "\n";
            playerTurn = false;
            playerHasChosen = true;
>>>>>>> 93bee04dd640b7cf53a7b6a602fccfa41fcf71a4
          }
        }
      }

    } else {
      // Handle enemy's attack here, if applicable
      player1.takeDamage(enemyInProximity->get_damage());
      playerTurn = true;
      std::cout << "You: \n"
                << "Health: " << player1.get_Health() << "/"
                << player1.get_maxHealth();
      std::cout << "\n Enemy: \n"
                << "Health: " << enemyInProximity->get_Health() << "/"
                << enemyInProximity->get_maxHealth() << "\n";

      render();
      playerHealthText.setString(
          "Health: " + std::to_string(player1.get_Health()) + "/100");
      window.draw(playerHealthText);
      enemyHealthText.setString(
          "Health: " + std::to_string(enemyInProximity->get_Health()) + "/100");
      window.draw(enemyHealthText);
      window.display();
    }
  }

  enemyInProximity->die();
  enemyInProximity = nullptr;
  inCombat = false;
  player1.add_Gold(15);
}





void Game::handleEvents() {
  // Handle game events here
  // Game loop
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
      // Combat check and handling

      if (!inCombat) {
        // Check for proximity to an enemy
        if (enemy1.isInProximityToPlayer(player1.get_x(), player1.get_y(),
                                         player1.get_depth()) == true &&
            enemy1.isAlive() == true) {
          enemyInProximity = &enemy1;
        } else if (enemy2.isInProximityToPlayer(
                       player1.get_x(), player1.get_y(), player1.get_depth()) &&
                   enemy2.isAlive()) {
          enemyInProximity = &enemy2;
        } else if (boss1.isInProximityToPlayer(player1.get_x(), player1.get_y(),
                                               player1.get_depth()) &&
                   boss1.isAlive()) {
          enemyInProximity = &boss1;
        }

        if (enemyInProximity) {
          inCombat = true;
          // You can add combat initialization logic here
          std::cout << "A battle has begun \n";
          playerTurn = true;
        }
      } else {
        // Handle combat logic here
        combat();
      }

      movement();
    }

    // Update the view to follow the player
    view.setCenter(player1.get_EntityPosition());

    // Set the view's size to control the area visible on the screen
    view.setSize(sf::Vector2f(800, 450));

    // Apply the view to the window
    window.setView(view);
    // Create chest entity
    render();

    window.display();

    // display player coordinates
    std::cout << player1.get_x() << " " << player1.get_y() << std::endl;
  }
}

void Game::render() {
  // Clear and Draw window
  window.clear();
  // Set background
  backgroundTexture.loadFromFile("images/GameMap4.png");
  sf::Sprite background(backgroundTexture);
  background.setPosition(0, 0);

  window.draw(background);
  if (enemy1.isAlive() == true) {
    enemy1.draw(&window);
  } else {
  }
  if (enemy2.isAlive() == true) {
    enemy2.draw(&window);
  }
  if (boss1.isAlive() == true) {
    boss1.draw(&window);
  }
  player1.draw(&window);
  mapCollision.drawRectangles(window);

  // Combat ui
  if (inCombat) {
    sf::Texture combatTexture;
    combatTexture.loadFromFile("images/Textbox.png");
    sf::Sprite combatTextBox(combatTexture);
    combatTextBox.setPosition(
        view.getCenter().x - combatTextBox.getGlobalBounds().width / 4,
        view.getCenter().y + 90);
    combatTextBox.setScale(0.5, 0.5);
    window.draw(combatTextBox);
    combatText.setPosition(window.getView().getCenter().x - 200,
                           window.getView().getCenter().y + 110);
    window.draw(combatText);
  }
<<<<<<< HEAD
if(inShop == true){
sf::Texture combatTexture;
=======
  //shop ui
  if (inShop == true) {
    sf::Texture combatTexture;
>>>>>>> 93bee04dd640b7cf53a7b6a602fccfa41fcf71a4
    combatTexture.loadFromFile("images/Textbox.png");
    sf::Sprite combatTextBox(combatTexture);
    combatTextBox.setPosition(
        view.getCenter().x - combatTextBox.getGlobalBounds().width / 4,
        view.getCenter().y + 90);
    combatTextBox.setScale(0.5, 0.5);
    window.draw(combatTextBox);
    shopText.setPosition(window.getView().getCenter().x - 200,
<<<<<<< HEAD
                           window.getView().getCenter().y + 110);
    window.draw(shopText);
}

}


=======
                         window.getView().getCenter().y + 110);
    window.draw(shopText);
  }
}
>>>>>>> 93bee04dd640b7cf53a7b6a602fccfa41fcf71a4
