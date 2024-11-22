#include <bits/stdc++.h>
using namespace std;
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
#include "Card.h"

Card::Card() : number(0), isFaceUp(false) {}

Card::Card(int num) : number(num), isFaceUp(false) {}

Card::~Card() {}

void Card::setNumber(int num) {
    number = num;
}

void Card::setFaceUp(bool faceUp) {
    isFaceUp = faceUp;
}

int Card::getNumber(){
    return number;
}

bool Card::getFaceUp(){
    return isFaceUp;
}

void Card::display(){
    if (isFaceUp) {
        cout << number;
    } else {
        cout << "*";
    }
}












int main() {
    Card c1(5);       // Create a card with number 5
    c1.display();     // Output: * (since it is face-down)
    cout << endl;
    c1.setFaceUp(true); // Flip the card face-up
    c1.display();       // Output: 5
    return 0;
}
