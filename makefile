output: entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o  main.o 
	g++  entity.o character.o player.o ranger.o mage.o fighter.o enemy.o map.o  main.o -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system -o run -Wall

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

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm *.o run
