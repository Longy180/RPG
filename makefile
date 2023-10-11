output: entity.o character.o player.o  enemy.o map.o  main.o 
	g++  entity.o character.o player.o enemy.o map.o  main.o  -lsfml-graphics -lsfml-window -lsfml-system -o run -Wall

entity.o: entity.cpp
	g++ -c entity.cpp

character.o: character.cpp
	g++ -c character.cpp

player.o: player.cpp
	g++ -c player.cpp

enemy.o: enemy.cpp
	g++ -c enemy.cpp

map.o: map.cpp
	g++ -c map.cpp

main.o: main.cpp
	g++ -c main.cpp 

clean:
	rm *.o run
