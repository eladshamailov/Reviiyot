#include "Game.h"
#include "fstream"
#include "sstream"
#include "string"

Game::Game(char *configurationFile)
        :players(),deck(),verbal(-1),numberOfTurns(0),n(-1){
    ifstream file;
    file.open(configurationFile);
    string content((std::istreambuf_iterator<char>(file)),
                   (std::istreambuf_iterator<char>()));
    int parameter = 0;
    string line;
    istringstream f(content);
    while (parameter <= 3) {
        getline(f, line);//trim
        if ((!line.empty()) && line.at(0) != '#') {
            if (parameter == 0) {//reading verbal parameter
                if (line.at(0) == '0')
                    verbal = 0;
                else
                    verbal = 1;
            } else if (parameter == 1) {//reading highest numeric value parameter
                n = stoi(line);
            } else if (parameter == 2) {//reading the deck parameter
                 deck =Deck(line, n);
            } else { // (parameter==3)reading the players
                int pos = 0;
                while (!line.empty()) {
                    vector<string> s(makeVec(line,' '));
                    int strategy = stoi(s[1]);
                    if (strategy == 1) {
                        PlayerType1* tmp=new PlayerType1(s[0],strategy);
                        players.push_back(tmp);

                    } else if (strategy == 2) {
                        PlayerType2* tmp=new PlayerType2(s[0],strategy);
                        players.push_back(tmp);

                    } else if (strategy == 3) {
                        PlayerType3* tmp=new PlayerType3(s[0],strategy);
                        players.push_back(tmp);

                    } else { // (strategy==4)
                        PlayerType4* tmp=new PlayerType4(s[0],strategy);
                        players.push_back(tmp);

                    }
                    pos++;
                    getline(f, line);
                }

            }
            parameter++;
        }
    }
}

void Game::makeVec(const string &st, char ch, vector<string> &v){
    stringstream ss;
    ss.str(st);
    string newItem;
    while (getline(ss, newItem,ch)){
        v.push_back(newItem);
    }
}

vector<string> Game::makeVec(const string &st, char ch){
    vector<string> e;
    makeVec(st,ch,e);
    return e;
}

void Game::play(){
    bool isWon=false;
    while (!isWon){
        for(int i=0;i<(int)players.size()&&(!isWon);i++){
            numberOfTurns=numberOfTurns+1;
            if(verbal==1) {
                cout<<"Turn "<<numberOfTurns<<endl;
                printState();
            }
            vector<int>temp;
            //temp=players[i]->getValue(players,deck,i,verbal);
            switch (players[i]->getPlayerTypeNum()){
                case 1:
                    temp=getValue1(i);
                    break;
                case 2:
                   temp=getValue2(i);
                    break;
                case 3:
                  temp=getValue3(i,players[i]->getCurrentPosition());
                    break;
                case 4:
                  temp=getValue4(i,players[i]->getCurrentPosition());
                    break;
            }
            int opponent=temp[0];
            int counter=temp[1];
            if (counter == 0) {
                if (!deck.isEmpty()) {
                    Card* c=deck.fetchCard();
                    players[i]->addCard(*c);
                    players[i]->checkIfFourAndDelete();
                }
            }
            else {
                if (players[opponent]->getNumberOfCards() > 0) {
                    for (int i = 0; i < counter; i++) {
                        if (!deck.isEmpty()) {
                            Card* c=deck.fetchCard();
                            players[opponent]->addCard(*c);
                        }
                    }
                }
            }
            players[opponent]->checkIfFourAndDelete();
            for(int h=0;h<(int)players.size()&&(!isWon);h++){
                if(players[h]->getNumberOfCards()==0){
                    isWon=true;
                }
            }
        }
    }
}

void Game::printNumberOfTurns(){
    cout<<"Number of turns: "<<numberOfTurns<<endl;
}

void Game::printState(){
    cout<<"Deck: "<<deck.toString()<<endl;
    for(int i=0;i<(int)players.size();i++){
        cout<<players[i]->toStringPlayer()<< endl;
    }
}

void Game::init(){
    for(int i=0;i<(int)players.size();i++){
        for(int j=0;j<7;j++){
            if(!deck.isEmpty()){
                Card* c=deck.fetchCard();
                players[i]->addCard(*c);
            }
        }
        players[i]->checkIfFourAndDelete();
    }
}

void Game::printWinner(){
    string winner1;
    string winner2="";
    bool foundFirstWinner=false;
    for(int i=0;i<(int)players.size();i++){
        if(players[i]->getNumberOfCards()==0){
            if(!foundFirstWinner){
                winner1=players[i]->getName();
                foundFirstWinner=true;
            }
            else{
                winner2=players[i]->getName();
            }
        }
    }
    if(winner2==""){
        cout<<"***** The Winner is: "<<winner1<<" "<<"*****"<<endl;
    }
    else{
        cout<<"***** The winners are: "<<winner1<<" "<<"and"<<" "<<winner2<<" "<<"*****"<<endl;
    }
}
vector<int> Game::getValue1(int myPlace){
    int maxSize = -1;
    int maxplayer = -1;
    vector<int>ans;
    for (int i = 0; i < (int)players.size(); i++) {
        if (i != myPlace) {
            if (players[i]->getNumberOfCards() >= maxSize) {
                maxSize = players[i]->getNumberOfCards();
                maxplayer = i;
            }
        }
    }
    ans.push_back(maxplayer);
    if (verbal == 1) {
        cout << players[myPlace]->getName() << " asked " << players[maxplayer]->getName() << " for the value "
             << players[myPlace]->getMaxCommonCard()->toString().substr(0, players[myPlace]->getMaxCommonCard()->toString().length() - 1) << endl;
        cout<<""<<endl;
    }
    int counter = 0;
    string s=players[myPlace]->getMaxCommonCard()->toString().substr(0,players[myPlace]->getMaxCommonCard()->toString().length()-1);
    while (players[maxplayer]->isThereStringValue(s)) {
        // Card* coo=getMaxCommonCard();
        players[myPlace]->addCard(*(players[maxplayer]->searchCardbyString(s)));
        players[maxplayer]->removeCard((*(players[maxplayer]->searchCardbyString(s))));
        counter++;
    }
    ans.push_back(counter);
    if (players[myPlace]->isFour(s)){
        players[myPlace]->deleteFour(s);
    }
    return ans;
}
vector<int> Game::getValue2(int myPlace){
    int maxSize=-1;
    int maxplayer=-1;
    vector<int>ans;
    for (int i=0; i<(int)players.size(); i++){
        if (i!=myPlace){
            if (players[i]->getNumberOfCards()>=maxSize){
                maxSize=players[i]->getNumberOfCards();
                maxplayer=i;
            }
        }
    }
    ans.push_back(maxplayer);
    if(verbal==1) {
        cout << players[myPlace]->getName() << " asked " << players[maxplayer]->getName() << " for the value "
             << players[myPlace]->getMinCommonCard()->toString().substr(0,players[myPlace]->getMinCommonCard()->toString().length()-1) << endl;
        cout<<""<<endl;
    }
    int counter=0;
    string s=players[myPlace]->getMinCommonCard()->toString().substr(0,players[myPlace]->getMinCommonCard()->toString().length()-1);
    while ((players[maxplayer]->isThereStringValue(s))){
        //    Card* coo=getMinCommonCard();
        players[myPlace]->addCard(*(players[maxplayer]->searchCardbyString(s)));
        players[maxplayer]->removeCard((*(players[maxplayer]->searchCardbyString(s))));
        counter++;
    }
    ans.push_back(counter);
    if (players[myPlace]->isFour(s)){
        players[myPlace]->deleteFour(s);
    }
    return ans;
}

vector<int> Game::getValue3(int myPlace,int currentPosition){
    vector<int>ans;
    if (players[myPlace]->getNumberOfCards() > 0) {
        if (currentPosition == myPlace) {
            currentPosition = currentPosition + 1;
        }
        if (currentPosition == (int)players.size()||
            (currentPosition == (int)players.size() && currentPosition == myPlace)) {
            currentPosition = 0;
        }
        ans.push_back(currentPosition);
        int counter = 0;
        if (verbal == 1) {
            cout << players[myPlace]->getName() << " asked " << players[currentPosition]->getName() << " for the value "
                 << players[myPlace]->getHighestCard()->toString().substr(0, players[myPlace]->getHighestCard()->toString().length() - 1)
                 << endl;
        cout<<""<<endl;
        }
        string s=players[myPlace]->getHighestCard()->toString().substr(0,players[myPlace]->getHighestCard()->toString().length()-1);
        while (players[currentPosition]->isThereStringValue(s)) {
            //  Card *coo = getHighestCard();
            players[myPlace]->addCard(*(players[currentPosition]->searchCardbyString(s)));
            players[currentPosition]->removeCard((*(players[currentPosition]->searchCardbyString(s))));
            counter++;
        }
        ans.push_back(counter);
        if (players[myPlace]->isFour(s)){
            players[myPlace]->deleteFour(s);
        }
    }
    currentPosition = currentPosition + 1;
    players[myPlace]->setCurrentPosition(currentPosition);
    return ans;

}
vector<int> Game::getValue4(int myPlace,int currentPosition){
    vector<int>ans;
    if (players[myPlace]->getNumberOfCards()>0) {
        if (currentPosition == myPlace) {
            currentPosition = currentPosition + 1;
        }
        if (currentPosition == (int)players.size()||
            (currentPosition == (int)players.size() && currentPosition == myPlace)) {
            currentPosition = 0;
        }
        ans.push_back(currentPosition);
        int counter = 0;
        if (verbal == 1) {
            cout << players[myPlace]->getName() << " asked " << players[currentPosition]->getName() << " for the value "
                 << players[myPlace]->getLowestCard()->toString().substr(0, players[myPlace]->getLowestCard()->toString().length() - 1)
                 << endl;
        cout<<""<<endl;
        }
        string s=players[myPlace]->getLowestCard()->toString().substr(0,players[myPlace]->getLowestCard()->toString().length()-1);
        while (players[currentPosition]->isThereStringValue(s)) {
            //    Card *coo = getLowestCard();
            players[myPlace]->addCard(*(players[currentPosition]->searchCardbyString(s)));
            players[currentPosition]->removeCard((*(players[currentPosition]->searchCardbyString(s))));
            counter++;
        }
        ans.push_back(counter);
        if (players[myPlace]->isFour(s)){
            players[myPlace]->deleteFour(s);
        }
    }
    currentPosition=currentPosition+1;
    players[myPlace]->setCurrentPosition(currentPosition);
    return ans;
}

Game::~Game() {
    for(int i=0;i<(int)players.size();i++){
        delete players[i];
    }
    while(!deck.isEmpty()){
        Card* c=deck.fetchCard();
        delete c;
    }
}

const Deck &Game::getDeck() const {
    return deck;
}

Game::Game(const Game &otherGame): players(),deck(otherGame.getDeck()), verbal(otherGame.verbal), numberOfTurns(otherGame.numberOfTurns), n(otherGame.n){
    for (int i=0; i<(int)otherGame.players.size(); i++){
        if (otherGame.players[i]->getPlayerTypeNum()==1){
            Player *tmp=new PlayerType1(*otherGame.players[i]);
            players.push_back(tmp);
        }
        else if (otherGame.players[i]->getPlayerTypeNum()==2){
            Player *tmp=new PlayerType2(*otherGame.players[i]);
            players.push_back(tmp);
        }
        else if (otherGame.players[i]->getPlayerTypeNum()==3){
            Player *tmp=new PlayerType3(*otherGame.players[i]);
            players.push_back(tmp);
        }
        else if (otherGame.players[i]->getPlayerTypeNum()==4){
            Player *tmp=new PlayerType4(*otherGame.players[i]);
            players.push_back(tmp);
        }
    }


}









