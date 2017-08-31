#include "Hand.h"

#include <iostream>
#include <vector>

using namespace std;

Hand::Hand(): playerCards(){};

Hand::Hand(vector<Card*>newPlayerCards): playerCards(){
    for (int i=0; i<(int)newPlayerCards.size();i++){
        this->playerCards.insert(playerCards.begin()+i,newPlayerCards[i]);
    }
}

int Hand::getNumberOfCards(){
    return (int)playerCards.size();
}

bool Hand::addCard(Card &card) {
    if (playerCards.size()==0)
        playerCards.push_back(&card);
    else {
        playerCards.insert(playerCards.begin() + whereToInsert(card), &card);
    }
    return  true;
}

bool Hand::removeCard(Card &card){
    if (searchPlace(card)!=-1) {
        this->playerCards.erase(playerCards.begin()+searchPlace(card));
        return true;
    }
    return false;
}

int Hand::searchPlace(Card &card){
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if (playerCards[i]->toString()==card.toString()){
            return i;
        }
    }
    return -1;
}
int Hand::searchPlaceByValue(string s){
    for (int i = 0; i <(int)(playerCards.size()) ; i++) {
        if (playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==s){
            return i;
        }
    }
    return -1;
}
int Hand::whereToInsert(Card &givenCard){
    for(int i=0;i<(int)(playerCards.size());i++){
        if(compareTo(&givenCard,playerCards[i])==-1){
            return i;
        }
    }
    return (int)(playerCards.size());
}

bool Hand::isFigure(string s) {
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
int Hand::compareTo(Card* a,Card* b) {
    if(isFigure(a->toString())){
        if(!isFigure(b->toString())){
            return 1;
        }
        else{
            string compareF="JQKA";
            string compareS="CDHS";
            if(compareF.find(a->toString().at(0))>compareF.find(b->toString().at(0))){
                return 1;
            }
            else{
                if(compareF.find(a->toString().at(0))<compareF.find(b->toString().at(0))){
                    return -1;
                }
                else{
                    if(compareS.find(a->toString().at(1))>compareS.find(b->toString().at(1))){
                        return 1;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
    }
    else{
        if(isFigure(b->toString())){
            return -1;
        }
        else{
            if(stoi(a->toString().substr(0,a->toString().length()-1))>stoi(b->toString().substr(0,b->toString().length()-1))){
                return 1;
            }
            else{
                if(stoi(a->toString().substr(0,a->toString().length()-1))<stoi(b->toString().substr(0,b->toString().length()-1))){
                    return -1;
                }
                else{
                    string compareS="CDHS";
                    if(compareS.find(a->toString().at(a->toString().length()-1))>compareS.find(b->toString().at(b->toString().length()-1))){
                        return 1;
                    }
                    else {
                        return -1;
                    }
                }
            }
        }
    }
}

string Hand::toString() {
    string ans = "";
    for (int i = 0; i < (int)playerCards.size(); i++) {
        ans = ans + playerCards[i]->toString();
        if(i!=(int)(playerCards.size())-1) {
            ans = ans + " ";
        }
    }
    return ans;
}

Card* Hand:: getMaxCommonCard(){
    int count=1;
    int maxCount=1;
    Card* ans=playerCards[0];
    for (int i = 0; i < (int)(playerCards.size())-1; i++) {
        if(playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==playerCards[i+1]->toString().substr(0,playerCards[i+1]->toString().length()-1)){
            count=count+1;
            if(count>maxCount){
                maxCount=count;
                ans=playerCards[i+1];
            }
            else{
                if (count==maxCount&&(compareTo(playerCards[i],ans)==1)){
                    ans=playerCards[i+1];
                }
            }
        }
        else{
            if((i==(int)playerCards.size()-2)&&(maxCount==1)){
                ans=playerCards[i+1];
            }
            count=1;
        }
    }
    return ans;
}

Card* Hand:: getMinCommonCard(){
    int count=1;
    int minCount=(int)playerCards.size();
    Card* ans=playerCards[0];
    for (int i = 0; i <(int)(playerCards.size())-1; i++) {
        if(playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==playerCards[i+1]->toString().substr(0,playerCards[i+1]->toString().length()-1)){
            count=count+1;
            if(i==(int)(playerCards.size())-2){
                if(count<minCount){
                    minCount=count;
                    ans=playerCards[i+1];
                }
            }
        }
        else{
            if(count<minCount){
                minCount=count;
                ans=playerCards[i];
            }
            if((i==(int)(playerCards.size())-2)&&(minCount>1)){
                ans=playerCards[i+1];
            }
            count=1;
        }
    }
    return ans;
}

Card* Hand::getHighestCard(){
    if((int)playerCards.size()>0) {
        return (playerCards[playerCards.size() - 1]);
    }
    return nullptr;
}

Card* Hand::getLowestCard(){
    if((int)playerCards.size()>0) {
        Card *c = playerCards[0];
        return (c);
    }
   return nullptr;
}

Card* Hand::searchCardbyValue(Card &card){
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==card.toString().substr(0,card.toString().length()-1))) {
            return playerCards[i];
        }
    }
    return nullptr;
}
bool Hand:: isThereStringValue(string s){
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==s)) {
            return true;
        }
    }
    return false;
}

Card* Hand::searchCardbyString(string stringValue){
    try{
        if(!isThereStringValue(stringValue)) {
            throw -1;
        }
        else {
            for (int i = 0; i <(int)playerCards.size() ; i++) {
                if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==stringValue)) {
                    return playerCards[i];
                }
        }
        }
    }
    catch (int e){
        if (e==-1){
            cout<<"no such card"<<endl;
        }
    }
    return nullptr;
}
bool Hand::checkIfFourAndDelete() {
    for(int i=0;i<(int)playerCards.size();i++){
                string s=playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1);
                if (isFour(s)){
                    deleteFour(s);
                    return true;
                }
    }
    return false;
}
bool Hand::isFour(Card &card){
    int count=0;
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==card.toString().substr(0,card.toString().length()-1))) {
            count++;
        }
    }
    if(count==4){
        return true;
    }
    else{
        return false;
    }
}

bool Hand::isFour(string s){
    int count=0;
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==s)) {
            count++;
        }
    }
    if(count==4){
        return true;
    }
    else{
        return false;
    }
}
void Hand::deleteFour(string s){//TODO add delete from memory option
    while(isThereStringValue(s)){
        Card* c=searchCardbyString(s);
        removeCard(*c);
        delete c;
    }
}

void Hand::deleteFour(Card &card){//TODO add delete from memory option
    for (int i = 0; i <(int)playerCards.size() ; i++) {
        if ((playerCards[i]->toString().substr(0,playerCards[i]->toString().length()-1)==(card.toString().substr(0,card.toString().length()-1)))) {
            removeCard(*playerCards[i]);
        }
    }
}

Hand::~Hand() {
    for(int i=0;i<(int)playerCards.size();i++){
        delete(playerCards[i]);
    }
}

Hand::Hand(const Hand &otherHand): Hand(){
    for (int i=0; i<(int)otherHand.playerCards.size();i++){
        Card* c=otherHand.playerCards[i];
        if (isFigure(c->toString())){
            if ((c->toString().at(0))=='J'){
                if (c->toString().at(1)=='C'){
                    playerCards.push_back(new FigureCard(Jack,Club));
                }
                if (c->toString().at(1)=='D'){
                    playerCards.push_back(new FigureCard(Jack,Diamond));
                }
                if (c->toString().at(1)=='H'){
                    playerCards.push_back(new FigureCard(Jack,Heart));
                }
                if (c->toString().at(1)=='S'){
                    playerCards.push_back(new FigureCard(Jack,Spade));
                }
            }
            else if ((c->toString().at(0))=='Q'){
                if (c->toString().at(1)=='C'){
                    playerCards.push_back(new FigureCard(Queen,Club));
                }
                if (c->toString().at(1)=='D'){
                    playerCards.push_back(new FigureCard(Queen,Diamond));
                }
                if (c->toString().at(1)=='H'){
                    playerCards.push_back(new FigureCard(Queen,Heart));
                }
                if (c->toString().at(1)=='S'){
                    playerCards.push_back(new FigureCard(Queen,Spade));
                }
            }
            else if ((c->toString().at(0))=='K'){
                if (c->toString().at(1)=='C'){
                    playerCards.push_back(new FigureCard(King,Club));
                }
                if (c->toString().at(1)=='D'){
                    playerCards.push_back(new FigureCard(King,Diamond));
                }
                if (c->toString().at(1)=='H'){
                    playerCards.push_back(new FigureCard(King,Heart));
                }
                if (c->toString().at(1)=='S'){
                    playerCards.push_back(new FigureCard(King,Spade));
                }
            }
            else if ((c->toString().at(0))=='A'){
                if (c->toString().at(1)=='C'){
                    playerCards.push_back(new FigureCard(Ace,Club));
                }
                if (c->toString().at(1)=='D'){
                    playerCards.push_back(new FigureCard(Ace,Diamond));
                }
                if (c->toString().at(1)=='H'){
                    playerCards.push_back(new FigureCard(Ace,Heart));
                }
                if (c->toString().at(1)=='S'){
                    playerCards.push_back(new FigureCard(Ace,Spade));
                }
            }
        }
        else{
            if ((c->toString().at((int)c->toString().size()-1))=='C'){
                playerCards.push_back(new NumericCard(stoi(c->toString().substr(0,c->toString().length()-1)),Club));
            }
            if ((c->toString().at((int)c->toString().size()-1))=='D'){
                playerCards.push_back(new NumericCard(stoi(c->toString().substr(0,c->toString().length()-1)),Diamond));
            }
            if ((c->toString().at((int)c->toString().size()-1))=='H'){
                playerCards.push_back(new NumericCard(stoi(c->toString().substr(0,c->toString().length()-1)),Heart));
            }
            if ((c->toString().at((int)c->toString().size()-1))=='S'){
                playerCards.push_back(new NumericCard(stoi(c->toString().substr(0,c->toString().length()-1)),Spade));
            }

        }

    }

}








