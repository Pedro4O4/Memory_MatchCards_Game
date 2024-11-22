#include <bits/stdc++.h>
using namespace std;
int speedUp = [] {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();
#include "Card.h"
#include "BonusCard.h"
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

BonusCard::BonusCard() : Card(), bonusPoints(0) {}

// Parameterized Constructor
BonusCard::BonusCard(int num, int points) : Card(num), bonusPoints(points) {}

// Destructor
BonusCard::~BonusCard() {}

// Setter for bonus points
void BonusCard::setBonusPoints(int points) {
    bonusPoints = points;
}

// Getter for bonus points
int BonusCard::getBonusPoints() {
    return bonusPoints;
}

// Overridden display method
void BonusCard::display(){
    if (getFaceUp()) {
        cout << getNumber() << " (Bonus: +" << bonusPoints << ")";
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
    cout<<endl;

    // Create a BonusCard with number 7 and bonus points of 2
    BonusCard bCard(7, 2);

    // Display the card (initially face-down)
    bCard.display(); // Output: *
    cout << endl;

    // Flip the card face-up
    bCard.setFaceUp(true);

    // Display the card again
    bCard.display(); // Output: 7 (Bonus: +2)
    return 0;
}
