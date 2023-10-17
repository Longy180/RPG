
#include "game.h"

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "animation.h"
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
      enemy2("Sprites/orc savage/OrcSavageIdleSide.gif", 1700, 280, 100, 100,
             5),
      boss1("Sprites/orc juggernaut/OrcJuggernautIdleSide.gif", 650, 700, 125,
            125, 8),
      animation() {
  // Initialize member variables and load resources here
  if (!font.loadFromFile("Fonts/VideoGame_Font.ttf")) {
    std::cout << "error loading font\n";
  }
  text.setFont(font);
  text.setCharacterSize(24);
  text.setFillColor(sf::Color::White);
  text.setString(
      "Choose your class:\n1. Fighter\n2. Mage\n3. Ranger\n\n\nControls:\nWASD "
      "or arrow keys to move\nE to access shop\nI to access inventory\nM to "
      "save\nL to load");
  text.setPosition(20.0f, 20.0f);

  combatText.setFont(font);
  combatText.setCharacterSize(24);
  combatText.setFillColor(sf::Color::White);

  // Initialise animation
  Animation animation;

  playerClass = 0;
  validChoice = false;
  inCombat = false;
  inShop = false;
  inInventory = false;
  enemyInProximity = nullptr;
  mapOpen = true;
  keyPressed = sf::Keyboard::Unknown;  // Initialize with an unknown key

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
    winLoseWindow();
  }
}

void Game::winLoseWindow() {
  text.setCharacterSize(24);
  text.setPosition(window.getView().getCenter().x - 100,
                   window.getView().getCenter().y - 50);

  if (player1.get_Health() <= 0) {
    text.setString("Game Over\nRan Out of Health");
  } else if (boss1.get_Health() <= 0) {
    text.setString("You Win\n");
  }
  window.clear();
  window.draw(text);
  window.display();
  sf::Event event;
  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }
}

void Game::chooseClass() {
  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        std::cout << "FILE SAVED" << std::endl;
        Game::Load("saveFile", player1, enemy1, enemy2, boss1);
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
          animation.set_charSelection(1);
          combatText.setString(
              "Your Turn:\n1. Tackle\n2. Takedown\n3. Recover");
          break;
        case 2:  // Mage
          std::cout << "You chose Mage." << std::endl;
          // Create Player
          player1 = Mage();
          animation.set_charSelection(2);
          combatText.setString(
              "Your Turn:\n1. Cast Fireball\n2. Summon Lightning\n3. Meditate");
          break;
        case 3:  // Ranger
          std::cout << "You chose Ranger." << std::endl;
          // Create Player
          player1 = Ranger();
          animation.set_charSelection(3);
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

void Game::movement() {
  if (!inCombat) {
    elapsedTime = clock.getElapsedTime();
    if (animation.get_lastMove() == 1) {
      animation.bodyMoveLeft(player1);
    } else if (animation.get_lastMove() == 2) {
      animation.bodyMoveRight(player1);
    }
    if (elapsedTime.asSeconds() > 0.1) {
      // Attempting to move LEFT
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) ||
          sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        if (mapCollision.willHit(player1) == false) {
          player1.move_left(12);
          animation.set_lastMove(1);
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
          animation.set_lastMove(2);
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
        clock.restart();
        // Shop logic
        int purchaseChoice = 0;
        inShop = true;

        text.setString("Your Gold: " + std::to_string(player1.get_Gold()) +
                       "\nItems 10 gold each:\n1. Tough Ring\n2. Tenacity "
                       "Ring\n3. Health Potion");

        std::cout << "Welcome to the shop\n";
        std::cout << "You have: " << player1.get_Gold() << " Gold.\n"
                  << "To purchase a Tough Ring for 10 gold press  1.\n"
                  << "To purchase a Tenacity Ring for 10 gold press 2.\n"
                  << "To purchase a Health Potion for 10 gold press 3.\n"
                  << "To exit the shop press 4.\n";

        while (inShop == true) {
          text.setCharacterSize(24);

          render();
          window.display();

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) &&
              clock.getElapsedTime().asSeconds() > 0.2) {
            clock.restart();
            AttackBoost* toughRing =
                new AttackBoost((std::string) "Tough Ring");

            if (player1.get_Gold() < toughRing->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou do not have enough gold.\nWe don't give out freebies "
                  "here!\nLeave by pressing 'E'\nCome back when you have gold");
            } else {
              player1.addToInventory(toughRing);
              player1.add_Gold(-10);
              std::cout << "You received a Tough Ring ! \n";
              toughRing->itemEffect(&player1);
              std::cout << "Your damage has increased by 3! \n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou received a Tough Ring ! \nYour damage has increased "
                  "by 3! \nPress 'E' to Exit the Shop");
            }

          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) &&
                     clock.getElapsedTime().asSeconds() > 0.2) {
            clock.restart();
            HealthBoost* tenacityRing =
                new HealthBoost((std::string) "Tenacity Ring");

            if (player1.get_Gold() < tenacityRing->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou do not have enough gold.\nWe don't give out freebies "
                  "here!\nLeave by pressing 'E'\nCome back when you have gold");
            } else {
              player1.addToInventory(tenacityRing);
              player1.add_Gold(-10);
              std::cout << "You received a Tenacity Ring ! \n";
              tenacityRing->itemEffect(&player1);
              std::cout << "Your max health has increased by 25! \n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou received a Tenacity Ring ! \nMax health has increased "
                  "by 25! \nPress 'E' to Exit the Shop");
            }

          } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) &&
                     clock.getElapsedTime().asSeconds() > 0.2) {
            clock.restart();
            HealthPotion* smallPotion =
                new HealthPotion((std::string) "Health Potion");

            if (player1.get_Gold() < smallPotion->get_buyPrice()) {
              std::cout << "You do not have enough gold.\n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou do not have enough gold.\nWe don't give out freebies "
                  "here!\nLeave by pressing 'E'\nCome back when you have gold");
            } else {
              player1.addToInventory(smallPotion);
              player1.add_Gold(-10);
              std::cout << "You received a Health Potion! \n";
              std::cout << "Open your inventory to use an item. \n";
              text.setString(
                  "Your Gold: " + std::to_string(player1.get_Gold()) +
                  "\nYou received a Health Potion! \nOpen your inventory to "
                  "use a potion. \nPress 'E' to Exit the Shop");
            }
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) &&
              clock.getElapsedTime().asSeconds() > 0.5) {
            inShop = false;
          }
        }
        clock.restart();

        // Inventory
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) &&
          clock.getElapsedTime().asSeconds() > 0.5) {
        clock.restart();
        inInventory = true;

        std::stringstream ss;
        ss << "Use number keys to select an item to use\nInventory: \n";

        currSize = player1.get_currInventorySize();

        if (currSize <= 0) {
          std::cout << "Inventory is empty\n";
          text.setString("Inventory: \nInventory is empty\n");
        } else {
          for (int i = 0; i < currSize; i++) {
            ss << (i + 1) << ". " << player1.getInventoryItem(i)->get_name()
               << "\n";
          }
          text.setString(ss.str());
        }

        render();
        window.display();

        sf::Event event1;
        bool playerHasChosen = false;
        int itemSelect = 0;

        while (inInventory && !playerHasChosen) {
          while (window.pollEvent(event1)) {
            if (event1.type == sf::Event::TextEntered) {
              if (event1.text.unicode >= '1' && event1.text.unicode <= '4') {
                itemSelect = event1.text.unicode - '0';
                playerHasChosen = true;
              }
            }
          }

          // Check for key presses for item selection
          for (int i = sf::Keyboard::Num1; i <= sf::Keyboard::Num4; ++i) {
            if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(i))) {
              itemSelect = i - sf::Keyboard::Num1 + 1;
              playerHasChosen = true;
              break;
            }
          }

          if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) &&
              clock.getElapsedTime().asSeconds() > 0.5) {
            inInventory = false;
          }
          sf::sleep(sf::milliseconds(
              100));  // Add a small delay to prevent excessive loop iterations.
        }

        if (playerHasChosen && itemSelect <= currSize) {
          if (player1.getInventoryItem(itemSelect - 1)->get_name() ==
              "Health Potion") {
            if (player1.get_Health() + 25 > player1.get_maxHealth()) {
              player1.set_Health(player1.get_maxHealth());
            } else {
              player1.set_Health(player1.get_Health() + 25);
            }
            std::cout << "Health increased by 25\n";
            player1.removeFromInventory(itemSelect - 1);
            std::cout << "Potion was discarded\n";
          } else {
            std::cout << "This item cannot be used now\n";
          }
        }
        clock.restart();

      }  // To save game state
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
        std::cout << "FILE SAVED" << std::endl;
        Game::Save("saveFile");
      }
      // To load game state
      else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
        std::cout << "FILE LOADED" << std::endl;
        Game::Load("saveFile", player1, enemy1, enemy2, boss1);
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
                             "/" + std::to_string(player1.get_maxHealth()));

  playerHealthText.setPosition(player1.get_EntityPosition().x,
                               player1.get_EntityPosition().y);
  window.draw(playerHealthText);

  enemyHealthText.setFont(font);
  enemyHealthText.setCharacterSize(12);
  enemyHealthText.setFillColor(sf::Color::White);
  enemyHealthText.setString(
      "Health: " + std::to_string(enemyInProximity->get_Health()) + "/" +
      std::to_string(enemyInProximity->get_maxHealth()));
  enemyHealthText.setPosition(enemyInProximity->get_EntityPosition().x,
                              enemyInProximity->get_EntityPosition().y - 20);
  window.draw(enemyHealthText);

  window.display();

  while (enemyInProximity->get_Health() > 0 && player1.get_Health() > 0) {
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
  if (enemyInProximity->get_Health() <= 0) {
    enemyInProximity->die();
    enemyInProximity = nullptr;
    player1.add_Gold(15);
  }
  inCombat = false;
}

void Game::Save(std::string fileName) {
  std::ofstream outFile(fileName);

  // Save player information to save file
  outFile << player1.get_Health() << std::endl;
  outFile << player1.get_x() << std::endl;
  outFile << player1.get_y() << std::endl;
  outFile << player1.get_Gold() << std::endl;
  outFile << player1.get_healingCounter() << std::endl;
  for (int i = 0; i < player1.get_currInventorySize(); i++) {
    outFile << player1.getInventoryItem(i) << std::endl;
  }
  outFile << enemy1.isAlive() << std::endl;
  outFile << enemy2.isAlive() << std::endl;
  outFile << boss1.isAlive() << std::endl;

  outFile.close();
}

void Game::Load(std::string fileName, Player& player1, Enemy& enemy1,
                Enemy& enemy2, Enemy& boss1) {
  std::ifstream inFile(fileName);

  int new_health;
  int new_x;
  int new_y;
  int new_gold;
  int new_healingCounter;
  bool enemy1Alive;
  bool enemy2Alive;
  bool boss1Alive;
  int location;
  // Save player information to save file
  // Setting health
  inFile >> new_health;
  player1.set_Health(new_health);

  // Checking position
  inFile >> new_x;
  inFile >> new_y;
  player1.set_position(new_x, new_y);

  // Checking gold count
  inFile >> new_gold;
  player1.set_gold(new_gold);

  inFile >> new_healingCounter;
  player1.set_healingCounter(new_healingCounter);

  inFile >> location;
if (location >= 0 && location < player1.get_currInventorySize()) {
    Item* newItem = new Item(location);  // Assuming you have a constructor that takes an item ID
    player1.addToInventory(newItem);
}

  // Checking enemy if alive
  inFile >> enemy1Alive;
  if (enemy1Alive == 0) {
    enemy1.die();
  } else {
    enemy1.revive();
  }

  inFile >> enemy2Alive;
  if (enemy2Alive == 0) {
    enemy2.die();
  } else {
    enemy2.revive();
  }

  inFile >> boss1Alive;
  if (boss1Alive == 0) {
    boss1.die();
  } else {
    boss1.revive();
  }

  inFile.close();
}

void Game::handleEvents() {
  // Handle game events here
  // Game loop
  while (window.isOpen() && player1.get_Health() > 0 &&
         boss1.get_Health() > 0) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        std::cout << "FILE SAVED" << std::endl;
        Game::Load("saveFile", player1, enemy1, enemy2, boss1);
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
      if (player1.get_Health() > 0) {
        movement();
      }
    }
    if (player1.get_Health() > 0) {
      // Update the view to follow the player
      view.setCenter(player1.get_EntityPosition());

      // Set the view's size to control the area visible on the screen
      view.setSize(sf::Vector2f(800, 450));

      // Apply the view to the window
      window.setView(view);
      // Create chest entity
      render();

      window.display();
    }
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
  //   mapCollision.drawRectangles(window);

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
  if (inShop == true) {
    sf::Texture combatTexture;
    combatTexture.loadFromFile("images/Textbox.png");
    sf::Sprite combatTextBox(combatTexture);
    combatTextBox.setPosition(
        view.getCenter().x - combatTextBox.getGlobalBounds().width / 4,
        view.getCenter().y);
    combatTextBox.setScale(0.5, 0.75);
    window.draw(combatTextBox);

    text.setPosition(window.getView().getCenter().x - 240,
                     window.getView().getCenter().y + 50);
    window.draw(text);
  }
  if (inInventory == true) {
    sf::Texture combatTexture;
    combatTexture.loadFromFile("images/Textbox.png");
    sf::Sprite combatTextBox(combatTexture);
    combatTextBox.setPosition(
        view.getCenter().x - combatTextBox.getGlobalBounds().width / 4,
        view.getCenter().y);
    combatTextBox.setScale(0.5, 0.75);
    window.draw(combatTextBox);

    text.setPosition(window.getView().getCenter().x - 240,
                     window.getView().getCenter().y + 50);
    window.draw(text);
  }
}
