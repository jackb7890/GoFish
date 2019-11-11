#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "card.h"
#include "deck.h"
#include "player.h"
using namespace std;

int main(int argc, char* argv[]){
	//Output file setup
	ofstream outputFile("gofish_results.txt",ios::out);
	if (!outputFile.is_open()){
		outputFile << "Cannot open file gofish_results.txt" << endl;
		exit(-1);
	}
	//Game Setup
	cout << "Playing..." << endl;
	Deck d;
	d.shuffle();
	Player p1("P1");
	Player p2("P2");
	outputFile << "Start Game!" << endl;
	//Deal
	outputFile << "Dealing..." << endl;
	for (int i = 0;i <7;i++){
		p1.addCard(d.dealCard());
		p2.addCard(d.dealCard());
	}
	outputFile << "P1 initial hand" << endl << p1.showHand() << endl;
	outputFile << "P2 initial hand" << endl << p2.showHand() << endl;

	//Check for initial books
	Card temp1;
	Card temp2;
	while (p1.checkHandForBook(temp1,temp2)){
		p1.bookCards(temp1,temp2);
	}
	while (p2.checkHandForBook(temp1,temp2)){
		p2.bookCards(temp1,temp2);
	}
	outputFile << "P1 hand after initial books" << endl << p1.showHand() << endl;
	outputFile << "P2 hand after initial books" << endl << p2.showHand() << endl;

	outputFile << "P1 books" << endl << p1.showBooks() << endl;
	outputFile << "P2 books" << endl << p2.showBooks() << endl;

	outputFile << endl << "-----------------------------------------"<< endl;

	//Game Start
	bool isP1Turn = true;
	while (!(d.size() == 0 && p1.getHandSize() == 0 && p2.getHandSize()== 0)){
		if (isP1Turn){
			outputFile << "It is now P1's turn"<<endl;
			Card guess = p1.chooseCardFromHand();
			if (p1.getHandSize() != 0) outputFile << "P1 asks P2 for a " << guess.rankString(guess.getRank()) << endl;
			if (p1.getHandSize() == 0){
				isP1Turn = false;
				if (d.size() != 0){
					Card deal = d.dealCard();
					p1.addCard(deal);
					outputFile << "P1 has empty hand and drew a " << deal << endl;	
				}
				else{
					outputFile << "P1 has an empty hand but cannot draw because the deck is empty" << endl;
				}
			}
			else if (p2.rankInHand(guess)){
				outputFile << "P1 takes P2's " << guess.rankString(guess.getRank()) << " from P2 and books it" << endl;
				p1.addCard(p2.removeCardFromHand(guess));
				if(p1.checkHandForBook(temp1, temp2)){
					p1.bookCards(temp1, temp2);
				}
			}
			else{
				isP1Turn = false;
				if (d.size() != 0){
					Card deal = d.dealCard();
					p1.addCard(deal);
					outputFile << "P2 says \"Go Fish\" and P1 draws a " << deal << endl;
				}
				else{
					outputFile << "P2 says \"Go Fish\" but P1 cannot draw because the deck is empty" << endl;
				}
				if(p1.checkHandForBook(temp1, temp2)){
					p1.bookCards(temp1, temp2);
					outputFile << "but alas P1 drew a match and booked it!" << endl;
				}
			}
			outputFile << "P1 ends his turn" << endl;
		}

		else{
			outputFile << "It is now P2's turn"<<endl;
			Card guess = p2.chooseCardFromHand();
			if (p2.getHandSize() != 0) outputFile << "P2 asks P1 for a " << guess.rankString(guess.getRank()) << endl;
			if (p2.getHandSize() == 0){
				isP1Turn = true;
				if (d.size() != 0){
					Card deal = d.dealCard();
					p2.addCard(deal);
					outputFile << "P2 has empty hand and drew a " << deal << endl;	
				}
				else{
					outputFile << "P2 has an empty hand but cannot draw because the deck is empty" << endl;
				}
			}
			else if (p1.rankInHand(guess)){
				outputFile << "P2 takes P1's " << guess.rankString(guess.getRank()) << " from P1 and books it" << endl;
				p2.addCard(p1.removeCardFromHand(guess));
				if(p2.checkHandForBook(temp1, temp2)){
					p2.bookCards(temp1, temp2);
				}
			}
			else{
				isP1Turn = true;
				if (d.size() != 0){
					Card deal = d.dealCard();
					p2.addCard(deal);
					outputFile << "P1 says \"Go Fish\" and P2 draws a " << deal << endl;
				}
				else{
					outputFile << "P1 says \"Go Fish\" but P2 cannot draw because the deck is empty" << endl;
				}
				if(p2.checkHandForBook(temp1, temp2)){
					p2.bookCards(temp1, temp2);
					outputFile << "but alas P2 drew a match and booked it!" << endl;
				}
			}
		}
		outputFile << endl;
	}
	int p1Books = p1.getBookSize();
	int p2Books = p2.getBookSize();
	if (p1Books > p2Books){
		outputFile << "P1 won the game with " << p1Books << " books" << endl<<"GAME OVER"<<endl;
	}
	else if(p2Books > p1Books){
		outputFile << "P2 won the game with " << p2Books << " books" << endl<<"GAME OVER"<<endl;
	}
	else{
		outputFile << "P1 and P2 tied\nGAME OVER" << endl;
	}
	cout << "GAME OVER" << endl;
}

