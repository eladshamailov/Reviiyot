#include "Card.h"
#include <iostream>

using namespace std;
//Card
Card::Card(Shape newShape): shape(newShape){ //constructor of Card
   
};
Card::~Card() {
}

Shape Card::getShape() const {
    return shape;
}

char Card::firstLetterOfShape(Shape shape){//returns the first letter of the shape
    
switch (shape){
        case(Club):
            return 'C';
        case (Diamond):
            return 'D';
        case (Heart):
            return 'H';
        case (Spade):
            return 'S';
        default:
        return 'C';
    }

}

int Card::getShapeValue(){
    switch (shape){
        case(Club):
            return 1;
        case (Diamond):
            return 2;
        case (Heart):
            return 3;
        case (Spade):
            return 4;
        default:
        return 1;
    }
}
Card::Card(const Card &otherCard): shape(otherCard.getShape()){}

FigureCard::FigureCard(Figure newFigure,Shape newShape):Card(newShape),figure(newFigure) {} //constructor of Figure Card


char FigureCard::firstLetterOfFigure(Figure figure){//returns the first letter of the figure
    switch (figure){
        case(King):
            return 'K';
        case (Queen):
            return 'Q';
        case (Jack):
            return 'J';
        case (Ace):
            return 'A';
        default:
        return 'K';
    }
}
string FigureCard:: toString(){
    return string() + firstLetterOfFigure(figure)+firstLetterOfShape(getShape());
}
Figure FigureCard::getFigure() const {
    return figure;
}

FigureCard::~FigureCard() {

}
FigureCard::FigureCard(const FigureCard &otherCard):Card(otherCard.getShape()), figure(otherCard.getFigure()){}



//NumericCard
NumericCard::NumericCard(int newNumber,Shape newShape) : Card(newShape), number(newNumber) {}
string NumericCard:: toString(){
    return to_string(number)+firstLetterOfShape(getShape());
}

int NumericCard::getNumber() const {
    return number;
}

NumericCard::~NumericCard() {

}


NumericCard::NumericCard(const NumericCard &otherCard):Card(otherCard.getShape()), number(otherCard.getNumber()){}

