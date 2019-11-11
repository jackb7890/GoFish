#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player(){
	myName = "default";
}

void Player::addCard(Card c){
	myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2){
	myBook.push_back(c1);
	myBook.push_back(c2);
	removeCardFromHand(c1);
	removeCardFromHand(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2){
	for (vector<Card>::iterator i = myHand.begin(); i != myHand.end(); i++){
		for (vector<Card>::iterator j=i+1; j != myHand.end(); j++){
			if (*i == *j){
				c1 = *i;
				c2 = *j;
				return true;
			}
		}
	}
	return false;
}

bool Player::rankInHand(Card c) const{
	for (vector<Card>::const_iterator i = myHand.begin(); i != myHand.end(); i++){
		if (c.getRank() == i->getRank()) return true;
	}
	return false;
}

Card Player::chooseCardFromHand() const{
	if (myHand.size() > 0) return myHand[0];
	Card c;
	return c;
}

//USELESS
bool Player::cardInHand(Card c) const{
	for (vector<Card>::const_iterator i = myHand.begin(); i != myHand.end(); i++){
		if (c == *i) return true;
	}
	return false;
}	

Card Player::removeCardFromHand(Card c){
	for (vector<Card>::const_iterator i = myHand.begin(); i != myHand.end(); i++){
		if (c == *i){
			Card c = *i;
			myHand.erase(i);
			return c;
		}
	}
	Card returnCard;
	return returnCard;
}

string Player::showHand() const{
	string handStr = "";
	for (vector<Card>::const_iterator i = myHand.begin(); i != myHand.end(); i++){
		handStr += i->toString() + "\n";
	}
	return handStr;
}

string Player::showBooks() const{
	string bookStr = "";
	for (vector<Card>::const_iterator i = myBook.begin(); i != myBook.end(); i+=2){
		bookStr += i->toString() + " & " + (i+1)->toString() + "\n";
	}
	return bookStr;
}

int Player::getHandSize() const{
	return myHand.size();
}

int Player::getBookSize() const{
	return myBook.size()/2;
}


