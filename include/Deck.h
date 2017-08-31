#ifndef DECK_H_
#define DECK_H_
#include <queue>
#include <iostream>

#include "Card.h"

using namespace std;


class Deck {
private:
	// Declare here the collection of "Card *" of the deck
	vector<Card*>myDeck;
	int numberOfCards;
public:
	Deck();
	Deck(string& line,int n);

	virtual ~Deck();

	Card* fetchCard();   //Returns the top card of the deck and remove it rom the deck
	int getNumberOfCards()const; // Get the number of cards in the deck
	string toString(); // Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"
	void bulidFigureCard(string& temp);
	void bulidNumericCard(string& temp);
	bool isFigure(string s);
	bool isEmpty();
	void clearDeck();
    Deck(const Deck &otherDeck);
};

#endif
