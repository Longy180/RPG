output: item.o oldWeapon.o entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o collision.o main.o 
	g++  item.o oldWeapon.o entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o collision.o main.o -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -o run -Wall

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

oldWeapon.o: oldWeapon.cpp
	g++ -c oldWeapon.cpp

main.o: main.cpp
	g++ -c main.cpp 

collision.o: collision.cpp
	g++ -c collision.cpp

clean:
	rm *.o run
