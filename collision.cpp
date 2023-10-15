#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <string>

#include "player.h"
#include "collision.h"

Collision::Collision(){
  rectangles[0].setSize(sf::Vector2f(1275, 25));
  rectangles[0].setPosition(0, 425); // Set position as needed
  rectangles[1].setSize(sf::Vector2f(100, 25));
  rectangles[1].setPosition(1325, 425); // Set position as needed
}

void Collision::removeCollision(){

}

// This is for debugging to show where the hitboxes are
void Collision::drawRectangles(sf::RenderWindow& window) {
    for (int i = 0; i < 10; i++) {
        window.draw(rectangles[i]);
    }
}


// bool Collision::willHitUp(){
// if player1.get_x()  player1.get_y()
// }

// bool Collision::willHitDown(){
// if player1.get_x()  player1.get_y()
// }

// bool Collision::willHitLeft(){
// if player1.get_x()  player1.get_y()
// }

// bool Collision::willHitRight(){
// if player1.get_x()  player1.get_y()
// }