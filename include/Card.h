#ifndef CARD_H_
#define CARD_H_

#include <iostream>
//#include <sstream>

using namespace std;

enum Shape {
    Club,
    Diamond,
    Heart,
    Spade
};

enum Figure {
    Jack,
    Queen,
    King,
    Ace
};

class Card {
private:
    Shape shape;
public:
    Card(Shape newshape);
    Shape getShape() const;
    char firstLetterOfShape(Shape shape);
    virtual int getShapeValue();//returns the value of the shape
    //virtual int getCardValue()=0;//returns the cardvalue
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"
    virtual ~Card();
    Card(const Card &otherCard);
    Card& operator=(const Card &otherCard);
};

class FigureCard : public Card {
private:
    Figure figure;
public:
    FigureCard(Figure newFigure,Shape newShape);

    virtual ~FigureCard();
    virtual string toString() override;
    char firstLetterOfFigure(Figure figure);
// virtual int getCardValue() override ;
//    int compareTo(FigureCard* card2); //this function compares two cards and returns the bigger one
    Figure getFigure() const;
    FigureCard(const FigureCard &otherCard);
    FigureCard& operator=(const FigureCard &otherCard);
};

class NumericCard : public Card {
private:
    int number;
public:
    NumericCard(int newNumber, Shape newShape);

    virtual ~NumericCard();

    virtual string toString() override;
    //virtual int getCardValue() override ;
    int getNumber() const;

//    int compareTo(NumericCard* card2); //this function compares two cards and returns the bigger one
    NumericCard(const NumericCard &otherCard);
    NumericCard& operator=(const NumericCard &otherCard);
};

#endif