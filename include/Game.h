#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "Player.h"
#include "Deck.h"

using namespace std;

class Game {
private:
	vector<Player *> players;  //The list of the players
	Deck deck;                 //The deck of the game
	int verbal;
	int numberOfTurns;
	int n;
public:
	Game(char* configurationFile);
	virtual ~Game();

	const Deck &getDeck() const;

	void init();
	void play();
	void printState();        //Print the state of the game as described in the assignment.
	void printWinner();       //Print the winner of the game as describe in the assignment.
        void printNumberOfTurns(); //Print the number of played turns at any given time.
	void makeVec(const string &st, char ch, vector<string> &v);
    vector<int> getValue1(int myPlace);
    vector<int> getValue2(int myPlace);
    vector<int> getValue3(int myPlace,int currentPosition);
    vector<int> getValue4(int myPlace,int currentPosition);
    vector<string> makeVec(const string &st, char ch);
	Game(const Game &otherGame);
};

#endif

