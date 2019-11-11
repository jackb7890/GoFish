#include <iostream>
#include <string>
#include "card.h"
using namespace std;

Card::Card(){
	mySuit = spades;
	myRank = 1;
}

Card::Card(int _rank, Suit _s){
	mySuit = _s;
	myRank = _rank;
}

string Card::toString() const{
	return rankString(myRank)+suitString(mySuit);
}

bool Card::sameSuitAs(const Card& c) const{
	if (mySuit == c.mySuit) return true;
	return false;
}

int Card::getRank() const{
	return myRank;
}

string Card::suitString(Suit s) const{
	string suitStr = "";
	switch (s){
		case spades: suitStr="s";
					 break;
		case hearts: suitStr="h";
					 break;
		case diamonds: suitStr="d";
					   break;
		case clubs: suitStr="c";
				    break;
	}
	return suitStr;
}

string Card::rankString(int r) const{
	string rankStr = "";
	switch (r){
		case 1: rankStr="A";
				break;
		case 11: rankStr="J";
				 break;
		case 12: rankStr="Q";
				 break;
		case 13: rankStr="K";
				 break;
		default: rankStr=to_string(r);
				 break;
	}
	return rankStr;
}

bool Card::operator ==(const Card& rhs) const {
	if(myRank == rhs.myRank) return true;
	return false;
}

bool Card::operator !=(const Card& rhs) const{
	if (myRank == rhs.myRank) return false;
	return true;
}

ostream& operator << (ostream& out, const Card& c){
	out << c.toString();
	return out;
}
