
#include "Card.h"
#include "Player.h"
#include <iostream>
#include "Deck.h"

using namespace std;

Player::Player(string givenName):Hand(),name(givenName),currentPosition(0){}

string Player::toStringPlayer() {
    return string() + getName() +": "+this->toString();
}

string Player::getName()const {
    return name;
}

Player::~Player() {

}


PlayerType1::PlayerType1(string givenName,int type) :Player(givenName),currentPosition(0),playerTypeNum(type) {}

PlayerType2::PlayerType2(string givenName,int type) : Player(givenName),currentPosition(0),playerTypeNum(type) {}

PlayerType3::PlayerType3(string givenName,int type): Player(givenName),currentPosition(0),playerTypeNum(type) {}

PlayerType4::PlayerType4(string givenName,int type): Player(givenName),currentPosition(0),playerTypeNum(type) {}

PlayerType1::~PlayerType1() {

}

int PlayerType1::getPlayerTypeNum() const {
    return playerTypeNum;
}


PlayerType2::~PlayerType2() {

}

int PlayerType2::getPlayerTypeNum() const {
    return playerTypeNum;
}

PlayerType3::~PlayerType3() {

}

int PlayerType3::getCurrentPosition() const {
    return currentPosition;
}

int PlayerType3::getPlayerTypeNum() const {
    return playerTypeNum;
}


PlayerType4::~PlayerType4() {

}

int PlayerType4::getPlayerTypeNum() const {
    return playerTypeNum;
}

Player::Player(const Player &otherPlayer) :Hand(otherPlayer),name(otherPlayer.getName()),currentPosition(0){}


PlayerType1::PlayerType1(const Player &otherPlayer1): Player::Player(otherPlayer1),currentPosition(0),playerTypeNum(1){}

int PlayerType1::getCurrentPosition() const {
    return currentPosition;
}

void PlayerType1::setCurrentPosition(int currentPosition) {
    PlayerType1::currentPosition = currentPosition;
}

PlayerType2::PlayerType2(const Player &otherPlayer2): Player::Player(otherPlayer2),currentPosition(0),playerTypeNum(2) {

}

int PlayerType2::getCurrentPosition() const {
    return currentPosition;
}

void PlayerType2::setCurrentPosition(int currentPosition) {
    PlayerType2::currentPosition = currentPosition;
}


PlayerType3::PlayerType3(const Player &otherPlayer3): Player::Player(otherPlayer3),currentPosition(0),playerTypeNum(3) {

}

void PlayerType3::setCurrentPosition(int currentPosition) {
    PlayerType3::currentPosition = currentPosition;
}


PlayerType4::PlayerType4(const Player &otherPlayer4): Player::Player(otherPlayer4),currentPosition(0),playerTypeNum(4) {

}

void PlayerType4::setCurrentPosition(int currentPosition) {
    PlayerType4::currentPosition = currentPosition;
}

int PlayerType4::getCurrentPosition() const {
    return currentPosition;
}
