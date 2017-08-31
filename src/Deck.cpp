#include <iostream>
#include "Deck.h"
#include "Card.h"
#include <deque>
#include <iterator>
#include <tuple>

using namespace std;


Deck::Deck():myDeck(),numberOfCards(0) {
}

Deck::Deck(string& line,int n):myDeck(),numberOfCards(0) {
    string temp;
    for (int i=0; i<=(int)line.size(); i++){
        if (i==(int)line.size()){
            if (isFigure(temp)){
                bulidFigureCard(temp);;

temp.clear();
            }
            else{
                if (temp!="") {
                    bulidNumericCard(temp);
                }
            }
            temp.clear();
            numberOfCards=numberOfCards+1;
        }

        else {
            char c = line.at(i);
            if (c != ' ') {
                temp.push_back(c);
            } else if (c == ' ') {
                if (isFigure(temp)) {
                    bulidFigureCard(temp);;
                } else {
                    bulidNumericCard(temp);
                }
                temp.clear();
                numberOfCards = numberOfCards + 1;
            }
        }
    }
temp.clear();
}

void Deck::bulidFigureCard(string& temp) {
    switch (temp.at(0)){
        case 'J': if (temp.at(1)=='C'){
                temp.clear();
                myDeck.push_back(new FigureCard(Jack,Club));
                break;
            }
            else if (temp.at(1)=='D'){
temp.clear();
               // Card* toPut=new FigureCard(Jack,Diamond);
                myDeck.push_back(new FigureCard(Jack,Diamond));
                break;
            }
            else if (temp.at(1)=='H'){
           temp.clear();
             //   Card* toPut=new FigureCard(Jack,Heart);
                myDeck.push_back(new FigureCard(Jack,Heart));
                break;
            }
            else{
temp.clear();
             //   Card* toPut=new FigureCard(Jack,Spade);
                myDeck.push_back(new FigureCard(Jack,Spade));
                break;
            }
            break;
        case 'Q': if (temp.at(1)=='C'){
temp.clear();
                //Card* toPut=new FigureCard(Queen,Club);
                myDeck.push_back(new FigureCard(Queen,Club));
                break;
            }
            else if (temp.at(1)=='D'){
temp.clear();
              //  Card* toPut=new FigureCard(Queen,Club);
                myDeck.push_back(new FigureCard(Queen,Diamond));
                break;
            }
            else if (temp.at(1)=='H'){
temp.clear();
                myDeck.push_back(new FigureCard(Queen,Heart));
                break;
            }
            else{
temp.clear();
                myDeck.push_back(new FigureCard(Queen,Spade));
                break;
            }
            break;
        case 'K': if (temp.at(1)=='C'){
temp.clear();
                myDeck.push_back(new FigureCard(King,Club));
                break;
            }
            else if (temp.at(1)=='D'){
temp.clear();
                myDeck.push_back(new FigureCard(King,Diamond));
                break;
            }
            else if (temp.at(1)=='H'){
temp.clear();
                myDeck.push_back(new FigureCard(King,Heart));
                break;
            }
            else{
temp.clear();
                myDeck.push_back(new FigureCard(King,Spade));
                break;
            }
            break;
        case 'A': if (temp.at(1)=='C'){
temp.clear();
                myDeck.push_back(new FigureCard(Ace,Club));
                break;
            }
            else if (temp.at(1)=='D'){
temp.clear();
                myDeck.push_back(new FigureCard(Ace,Diamond));
                break;
            }
            else if (temp.at(1)=='H'){
temp.clear();
                myDeck.push_back(new FigureCard(Ace,Heart));
                break;
            }
            else{
temp.clear();
                myDeck.push_back(new FigureCard(Ace,Spade));
                break;
            }
        default:
            myDeck.push_back(new FigureCard(Jack,Club));
            break;
    }
temp.clear();
}

void Deck::bulidNumericCard(string& temp) {
    char c=temp.at(temp.length()-1);
    temp=temp.substr(0,temp.length()-1);
    int n=stoi(temp);
    temp.clear();
    if (c == 'C') {
        myDeck.push_back(new NumericCard(n, Club));
    } else if (c == 'D') {
        myDeck.push_back(new NumericCard(n, Diamond));
    } else if (c == 'H') {
        myDeck.push_back(new NumericCard(n, Heart));
    } else {
        myDeck.push_back(new NumericCard(n, Spade));
    }
}

bool Deck::isFigure(string s) {
    if (s=="")
        return false;
    switch (s.at(0)){
        case 'J':
            return true;
        case 'Q':
            return true;
        case 'K':
            return true;
        case 'A':
            return true;
        default:
            return false;
    }
}

int Deck::getNumberOfCards()const {
    return numberOfCards;
}

Card* Deck::fetchCard(){
    try{
        if(myDeck.empty()){
            throw -1;
        }
        else{
            Card* c=myDeck.front();
            myDeck.erase(myDeck.begin());
            numberOfCards=numberOfCards-1;
            return c;
        }
    }
    catch (int e){
        if(e==-1){
            cout<<"no cards"<<endl;
        }
    }
return nullptr;
}

bool Deck:: isEmpty(){
    if (myDeck.empty())
        return true;
    else
        return false;
}

string Deck::toString() {
    string ans = "";
    for(auto it=myDeck.begin();it!=myDeck.end();it++) {
        ans=ans+(*it)->toString();
        ans=ans+ " ";
    }
    ans=ans.substr(0,ans.length()-1);
    return ans;
}

void Deck::clearDeck() {
    myDeck.clear();
}

Deck::~Deck() {
        myDeck.clear();
}
Deck::Deck(const Deck &otherDeck) :myDeck(), numberOfCards(otherDeck.getNumberOfCards()) {
    for (auto it = otherDeck.myDeck.begin(); it != otherDeck.myDeck.end(); it++) {
        Card *c = *it;
        if (isFigure(c->toString())) {
            if ((c->toString().at(0)) == 'J') {
                if (c->toString().at(1) == 'C') {
                    myDeck.push_back((Card*)new FigureCard(Jack, Club));
                }
                if (c->toString().at(1) == 'D') {
                    myDeck.push_back((Card*)new FigureCard(Jack, Diamond));
                }
                if (c->toString().at(1) == 'H') {
                    myDeck.push_back((Card*)new FigureCard(Jack, Heart));
                }
                if (c->toString().at(1) == 'S') {
                    myDeck.push_back((Card*)new FigureCard(Jack, Spade));
                }
            } else if ((c->toString().at(0)) == 'Q') {
                if (c->toString().at(1) == 'C') {
                    myDeck.push_back((Card*)new FigureCard(Queen, Club));
                }
                if (c->toString().at(1) == 'D') {
                    myDeck.push_back((Card*)new FigureCard(Queen, Diamond));
                }
                if (c->toString().at(1) == 'H') {
                    myDeck.push_back((Card*)new FigureCard(Queen, Heart));
                }
                if (c->toString().at(1) == 'S') {
                    myDeck.push_back((Card*)new FigureCard(Queen, Spade));
                }
            } else if ((c->toString().at(0)) == 'K') {
                if (c->toString().at(1) == 'C') {
                    myDeck.push_back((Card*)new FigureCard(King, Club));
                }
                if (c->toString().at(1) == 'D') {
                    myDeck.push_back((Card*)new FigureCard(King, Diamond));
                }
                if (c->toString().at(1) == 'H') {
                    myDeck.push_back((Card*)new FigureCard(King, Heart));
                }
                if (c->toString().at(1) == 'S') {
                    myDeck.push_back((Card*)new FigureCard(King, Spade));
                }
            } else if ((c->toString().at(0)) == 'A') {
                if (c->toString().at(1) == 'C') {
                    myDeck.push_back((Card*)new FigureCard(Ace, Club));
                }
                if (c->toString().at(1) == 'D') {
                    myDeck.push_back((Card*)new FigureCard(Ace, Diamond));
                }
                if (c->toString().at(1) == 'H') {
                    myDeck.push_back((Card*)new FigureCard(Ace, Heart));
                }
                if (c->toString().at(1) == 'S') {
                    myDeck.push_back((Card*)new FigureCard(Ace, Spade));
                }
            }
        } else {
            if ((c->toString().at((int) c->toString().size()-1)) == 'C') {
                myDeck.push_back((Card*)new NumericCard(stoi(c->toString().substr(0, c->toString().length() - 1)), Club));
            }
            if ((c->toString().at((int) c->toString().size()-1)) == 'D') {
                myDeck.push_back((Card*)
                        new NumericCard(stoi(c->toString().substr(0, c->toString().length() - 1)), Diamond));
            }
            if ((c->toString().at((int) c->toString().size()-1)) == 'H') {
                myDeck.push_back((Card*)
                        new NumericCard(stoi(c->toString().substr(0, c->toString().length() - 1)), Heart));
            }
            if ((c->toString().at((int) c->toString().size()-1)) == 'S') {
                myDeck.push_back((Card*)
                        new NumericCard(stoi(c->toString().substr(0, c->toString().length() - 1)), Spade));
            }

        }

    }
}
