#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "spell.h"

class Player {
    private:
        sf::CircleShape* body;
        int _depth;
    public:
        Player(int r, int x, int y, int num_O_Spells){
            body = new sf::CircleShape();
            body->setRadius(r);
            body->setPosition(x,y);
            body->setFillColor(sf::Color::Green);
            body->setOrigin(r/2,r/2);
            _depth = r;
        }
        void draw(sf::RenderWindow* win){
            win->draw(*body);
        }

        int get_x(){
            return body->getPosition().x;
        }
        int get_y(){
            return body->getPosition().y;
        }
        int get_depth(){
            return _depth;
        }

        
        void move_right(int speed){
            body->move(speed,0);
        }
        void move_left(int speed){
            body->move(-speed,0);
        }
        void move_up(int speed){
            body->move(0,-speed);
        }
        void move_down(int speed){
            body->move(0,speed);
        }

        bool isHit(int t_x,int t_y, int t_depth){
            bool hit = false;

            return hit;
        }


        ~Player(){
            delete this->body;
        }
};

#endif