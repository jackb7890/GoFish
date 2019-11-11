#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "card.h"
#include "deck.h"

using namespace std;

Deck::Deck(){
	int dIndex = 0;
	for (int i = 0; i < 4; i++){
		for (int j = 1; j < 14; j++){
			Card temp(j, (Card::Suit)i);
			myCards[dIndex] = temp;
			dIndex++;
		}
	}
	
	myIndex = 0;

	srand(time(NULL));
}

void Deck::shuffle(){
	for (int i = 0; i < 100; i++){
		int rand1 = rand() % 52;
		int rand2 = rand() % 52;
		Card temp = myCards[rand1];
		myCards[rand1] = myCards[rand2];
		myCards[rand2] = temp;
	}
}

Card Deck::dealCard(){
	myIndex++;
	return myCards[myIndex - 1];
}

int Deck::size() const{
	return 52 - myIndex;
}
