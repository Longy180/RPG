#include <SFML/Graphics.hpp>
#include <iostream>

class Map {
    private:
        sf::Sprite* body;
        int _depth;
    public:
            
        Map(int r, int x, int y){
            body = new sf::Sprite();
            body->setPosition(x,y);
            _depth = r; 

             //Set sprite
            sf::Image image;
        if (!(image.loadFromFile("images/map.jpeg")))
                std::cout << "Cannot load image";   //Load Image
        
        sf::Texture texture;
        texture.loadFromImage(image);

        body->setTexture(texture, true);    
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
            body->move(-speed,0);
        }
        void move_left(int speed){
            body->move(speed,0);
        }
        void move_up(int speed){
            body->move(0,speed);
        }
        void move_down(int speed){
            body->move(0,-speed);
        }

        ~Map(){
            delete this->body;
        }
};

