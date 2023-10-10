output: main.o enemy.o game.o map.o player.o spell.o
	g++ main.o enemy.o game.o map.o player.o spell.o -lsfml-graphics -lsfml-window -lsfml-system -o run -Wall

main.o: main.cpp
	g++ -c main.cpp 

enemy.o: enemy.cpp
	g++ -c enemy.cpp

game.o: game.cpp
	g++ -c game.cpp

map.o: map.cpp
	g++ -c map.cpp

player.o: player.cpp
	g++ -c player.cpp

spell.o: spell.cpp
	g++ -c spell.cpp

clean:
	rm *.o run
