#include <SFML/Graphics.hpp>
#include <random>
#include <time.h>
#include <cmath>

class Enemy
{
private:
    sf::RectangleShape* body;
    bool alive;
    int _depth;
public:
    Enemy(){
        _depth = 10;
        body = new sf::RectangleShape(sf::Vector2f(_depth,_depth));
        body->setFillColor(sf::Color::Cyan);
        body->setPosition(-1,-1);
        body->setOrigin(_depth/2,_depth/2);
        alive = false;
        srand(time(0));
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
    bool isAlive(){return alive;}
    void die(){alive = false;}
    void spawn(int x, int y){
        int rand_y = rand() % y + 1;
        body->setPosition(x,rand_y);
        this->alive = true;
    }

    bool isHit(int target_x, int target_y, int target_depth){
        bool hit = false;
        int x = get_x();
        int y = get_y();
        float dist_between = sqrt((x-target_x)*(x - target_x)+(y-target_y)*(y - target_y));
        if (dist_between < (_depth + target_depth)){
            hit = true;
        }
        return hit;
    }


    void draw(sf::RenderWindow* win){
        if(this->alive){
            body->move(-0.01,0);
            win->draw(*body);
            if(body->getPosition().x < 0){
                this->spawn(win->getSize().x-10, win->getSize().y);
            }
        }
    }

    ~Enemy(){
        delete this->body;
    }
};
