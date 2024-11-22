
#ifndef MEMORY_MATCHCARD_GAME_CARD_H
#define MEMORY_MATCHCARD_GAME_CARD_H
#include <bits/stdc++.h>
using namespace std;
class Card{
private:
    int  number;
    bool isFaceUp;
public:
    Card();
    Card(int value);
   virtual ~Card();


    void setNumber(int num);
    void setFaceUp(bool faceUp);


    int getNumber();
    bool getFaceUp() ;

    void display();

};
#endif //MEMORY_MATCHCARD_GAME_CARD_H
