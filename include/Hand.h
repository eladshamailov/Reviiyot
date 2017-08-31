#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include <iostream>

#include "Card.h"

using namespace std;

class Hand {
private:
	// Declare here the collection of "Card *" of the hand
	vector<Card*>playerCards;
	int whereToInsert(Card &givenCard);//returns the position where to enter the card

public:
    Hand();

	virtual ~Hand();

	Hand(vector<Card*>newPlayerCards);
	bool addCard(Card &card);
	bool removeCard(Card &card);
    virtual int searchPlace(Card &card);
	int getNumberOfCards(); // Get the number of cards in hand
	string toString(); // Return a list of the cards, separated by space, in one line,
	//in a sorted order, ex: "2S 5D 10H"
    bool isFigure(string s);
    int compareTo(Card* a,Card* b);
    Card* getMaxCommonCard();
    Card* getMinCommonCard();
    Card* getHighestCard();
    Card* getLowestCard();
	Card* searchCardbyValue(Card &card);
	int searchPlaceByValue(string s);
	Card* searchCardbyString(string stringValue);
	bool isThereStringValue(string s);
	bool checkIfFourAndDelete();
	bool isFour(Card &card);
	bool isFour(string s);
	void deleteFour(Card &card);
	void deleteFour(string s);
	Hand(const Hand &otherHand);
};

#endif
