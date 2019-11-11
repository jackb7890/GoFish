final: driver.o player.o deck.o card.o
	g++ -std=c++11 -o GoFish driver.o player.o deck.o card.o
driver.o: driver.cpp player.h deck.h card.h
	g++ -std=c++11 -c driver.cpp player.cpp deck.cpp card.cpp
player.o: player.cpp player.h deck.h card.h
	g++ -std=c++11 -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -std=c++11 -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++11 -c card.cpp
