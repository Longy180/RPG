output: item.o attackBoost.o healthBoost.o healthPotion.o entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o collision.o game.o animation.o main.o 
	g++  item.o attackBoost.o healthBoost.o healthPotion.o entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o collision.o game.o animation.o main.o -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -o run -Wall

entity.o: entity.cpp
	g++ -c entity.cpp

character.o: character.cpp
	g++ -c character.cpp

player.o: player.cpp
	g++ -c player.cpp

ranger.o: ranger.cpp
	g++ -c ranger.cpp

mage.o: mage.cpp
	g++ -c mage.cpp

fighter.o: fighter.cpp
	g++ -c fighter.cpp

enemy.o: enemy.cpp
	g++ -c enemy.cpp

map.o: map.cpp
	g++ -c map.cpp

item.o: item.cpp
	g++ -c item.cpp

attackBoost.o: attackBoost.cpp
	g++ -c attackBoost.cpp

healthBoost.o: healthBoost.cpp
	g++ -c healthBoost.cpp

healthPotion.o: healthPotion.cpp
	g++ -c healthPotion.cpp

main.o: main.cpp
	g++ -c main.cpp 

collision.o: collision.cpp
	g++ -c collision.cpp

game.o: game.cpp
	g++ -c game.cpp

animation.o: animation.cpp
	g++ -c animation.cpp

clean:
	rm *.o run
