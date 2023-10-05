#include <SFML/Graphics.hpp>
#include "spell.h"

class Player {
    private:
        sf::CircleShape* body;
        int numSpells;
        Spell* spells;
        int _depth;
    public:
        Player(int r, int x, int y, int num_O_Spells){
            body = new sf::CircleShape();
            body->setRadius(r);
            body->setPosition(x,y);
            body->setFillColor(sf::Color::Green);
            body->setOrigin(r/2,r/2);
            _depth = r;
            numSpells = num_O_Spells;
            spells = new Spell[100];
        }
        void draw(sf::RenderWindow* win){
            win->draw(*body);
            for (size_t i = 0; i < numSpells; i++)
            {
                if(spells[i].isFired()){
                    spells[i].move();
                    spells[i].draw(win);
                }
            }
            
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
            for(int i = 0; i < numSpells; i++){
                if (spells[i].isFired()){
                    if (spells[i].isHit(t_x, t_y, t_depth)){
                        hit = true;
                        return hit;
                    }
                }  
            }
            return hit;
        }

        void fire(){
            for (size_t i = 0; i < numSpells; i++)
            {
                if (!spells[i].isFired()){
                    spells[i].use(body->getPosition());
                    break;
                }
                
            }
            
        }
        ~Player(){
            delete this->body;
            delete [] this->spells;
        }
};

