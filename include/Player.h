#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include <Hand.h>
#include <Deck.h>

using namespace std;

class Player : public Hand {
private:
	const string name;
    int currentPosition;
public:
	Player(string givenName);
	string getName()const;   //Returns the name of the player
	string toStringPlayer();
//	virtual vector<int> getValue(vector<Player *> players,Deck deck ,int myPlace
//			,int verbal)=0;
	virtual ~Player();
	virtual int getPlayerTypeNum() const =0;

    virtual void setCurrentPosition(int currentPosition)=0;

    virtual int getCurrentPosition() const=0;

	Player(const Player &otherPlayer);
	Player& operator=(const Player &otherPlayer);
};

class PlayerType1 : public Player {  //For strategy 1
private:
    int currentPosition;
    int playerTypeNum;
public:
//	PlayerType1();
	virtual ~PlayerType1();

    PlayerType1(string givenName,int type);

//	vector<int> getValue(vector<Player *> players,Deck deck ,int myPlace,int verbal);
	int getPlayerTypeNum() const;

    virtual void setCurrentPosition(int currentPosition);

    virtual int getCurrentPosition() const;

    PlayerType1(const Player &otherPlayer1);

	PlayerType1& operator=(const PlayerType1 &otherPlayer1);
};



class PlayerType2 : public Player {  //For strategy 2
private:
    int currentPosition;
    int playerTypeNum;
public:
//    PlayerType2();
	virtual ~PlayerType2();

    PlayerType2(string givenName,int type);

//	vector<int> getValue(vector<Player *> players,Deck deck ,int myPlace,int verbal);

    virtual void setCurrentPosition(int currentPosition);

    int getPlayerTypeNum() const;

    virtual int getCurrentPosition() const;

    PlayerType2(const Player &otherPlayer2);

	PlayerType2& operator=(const PlayerType2 &otherPlayer2);

};

class PlayerType3 : public Player {  //For strategy 3
private:
    int currentPosition;
	int playerTypeNum;
public:
//    PlayerType3();

	virtual ~PlayerType3();

	PlayerType3(string givenName,int type);
//	vector<int> getValue(vector<Player *> players,Deck deck ,int myPlace,int verbal);

    virtual void setCurrentPosition(int currentPosition);

    virtual int getCurrentPosition() const;
	int getPlayerTypeNum() const;
	PlayerType3(const Player &otherPlayer3);
	PlayerType3& operator=(const PlayerType3 &otherPlayer3);
};

class PlayerType4 : public Player {  //For strategy 4
private:
    int currentPosition;
	int playerTypeNum;
public:
//    PlayerType4();

	virtual ~PlayerType4();

    virtual void setCurrentPosition(int currentPosition);

    PlayerType4(string givenName,int type);
//	vector<int> getValue(vector<Player *> players,Deck deck ,int myPlace,int verbal);

   virtual int getCurrentPosition() const;

    int getPlayerTypeNum() const;
	PlayerType4(const Player &otherPlayer4);
	PlayerType4& operator=(const PlayerType4 &otherPlayer4);
};

#endif

