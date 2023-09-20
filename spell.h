#include <SFML/Graphics.hpp>
#include <cmath>

class Spell
{
private:
    sf::RectangleShape* body;
    bool fired;
    int _depth;
public:
    Spell(){
        _depth = 5;
        body = new sf::RectangleShape(sf::Vector2f(_depth*2,_depth));
        body->setFillColor(sf::Color::Red);
        body->setPosition(-1,-1);
        body->setOrigin(_depth,_depth/2);
        fired = false;
    }
    void draw(sf::RenderWindow* win){
        win->draw(*body);
    }
    void set_position(sf::Vector2f position){
        body->setPosition(position);
    }
    void move(){
        body->move(0.5,0);
    }
    int get_x(){return body->getPosition().x;}
    int get_y(){return body->getPosition().y;}
    int get_depth(){return _depth;}
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
    bool isFired(){return fired;}
    void use(sf::Vector2f position){ 
        body->setPosition(position);
        fired = true;
    }



    ~Spell(){
        delete this->body;
    }
};
