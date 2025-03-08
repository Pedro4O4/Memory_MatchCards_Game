#include <bits/stdc++.h>
using namespace std;

#include "Card.h"
#include "StandardCard.h"
#include "BonusCard.h"
#include "PenaltyCard.h"
#include "Player.h"
#include "Deck.h"
#include "Game.h"

Card::Card() : value(0), isFaceUp(false) {

}
Card::Card(int value, bool isFaceUp) : value(value), isFaceUp(isFaceUp) {

}
Card::~Card() {

}

void Card:: setValue(int v) { value = v; }
void Card:: setIsfaceUp(bool f) { isFaceUp = f; }
int Card::getValue() { return value; }
bool Card::getIsfaceUp() { return isFaceUp; }
void Card::display() {
    if (isFaceUp) {
        cout<<value;
    }
     else {
        std::cout << "*";
    }
}
void Card::reveal() {
    isFaceUp = true;
}

void Card::hide() {
    isFaceUp = false;
}

bool Card::getIsFaceUp() {
    return isFaceUp;
}

StandardCard::StandardCard() : Card() {}
StandardCard::StandardCard(int value, bool isFaceUp) : Card(value, isFaceUp) {}
StandardCard::~StandardCard() {}
void StandardCard::display() {
    if (getIsFaceUp()) {
        std::cout << "StandardCard: " << getValue() << std::endl;
    } else {
        std::cout << "StandardCard: Face down" << std::endl;
    }
}

BonusCard::BonusCard() : Card(), bonusPoints(0) {}
BonusCard::BonusCard(int value,bool isFaceUp,  int  bonusPoints) : Card(value,isFaceUp), bonusPoints( bonusPoints ) {}

BonusCard::~BonusCard() {}

void BonusCard::setBonusPoints(int points) { bonusPoints ; }
int BonusCard::getBonusPoints() { return bonusPoints; }

void BonusCard::display() {
    if (getIsfaceUp()) {
        std::cout << "B" << getValue() << "(+" << bonusPoints << ")";
    } else {
        std::cout << "*";
    }
}




PenaltyCard::PenaltyCard(int value, bool isFaceUp, int penaltyPoints)
    : Card(value, isFaceUp), penaltyPoints(penaltyPoints) {}

PenaltyCard::~PenaltyCard() {}
void PenaltyCard::setPenaltyPoints(int points) { penaltyPoints; }
int PenaltyCard::getPenaltyPoints() { return penaltyPoints; }



void PenaltyCard::display() {
    if (getIsfaceUp()) {
        std::cout << "P" << getValue() << "(-" << penaltyPoints << ")";
    } else {
        std::cout << "*";
    }
}

Player::Player() : name("Player"), score(0) {}
Player::Player(string Pname,int s) : name(Pname), score(s) {}
Player::~Player() {}
void Player::setName(string Pname) { name = Pname; }
void Player::setScore(int s) { score = s; }
string Player::getName() { return name; }
int Player::getScore() { return score; }
void Player::displayScore() { cout << "Player: " <<name << " Score: " << score << endl; }
void Player::addScore(int points) { score += points; }
void Player::deduceScore(int points) { score -= points; }
Deck::Deck() {
    grid = new Card*[4];
    for (int i = 0; i < 4; i++) {
        grid[i] = new Card[4];
    }
    deck = new Card*[16];

    for (int i = 0; i < 16; i++) {
        if (i < 6) {
            deck[i] = new StandardCard((i % 6) + 1, false);
        } else if (i == 6 || i == 7) {
            deck[i] = new BonusCard(7, false, 2);
        } else if (i == 8 || i == 9) {
            deck[i] = new PenaltyCard(8, false, 2);
        } else {
            deck[i] = new StandardCard((i % 6) + 1, false);
        }
    }

    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = *deck[index++];
        }
    }
}


Card& Card::operator=(std::nullptr_t null) {
    value = 0;
    isFaceUp = false;
    return *this;
}
void Deck::removeCards(Card* c1, Card* c2) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (&grid[i][j] == c1 || &grid[i][j] == c2) {
                grid[i][j] = nullptr; // Set the matched card to nullptr
            }
        }
    }
}
bool Card::operator!=(std::nullptr_t null) const {
    return value != 0 || isFaceUp != false;
}

Deck::~Deck() {
    for (int i = 0; i < 4; i++) delete[] grid[i];
    delete[] grid;
    delete[] deck;
}

void Deck::shuffle() {
    srand(static_cast<unsigned>(time(0)));


    Card temp[16];
    int index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp[index++] = grid[i][j];
        }
    }


    for (int i = 15; i > 0; i--) {
        int j = rand() % (i + 1);
        Card tempCard = temp[i];
        temp[i] = temp[j];
        temp[j] = tempCard;
    }


    index = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            grid[i][j] = temp[index++];
        }
    }
}



void Deck::displayGrid() {
    int c = 1;
    cout<<"     "<<"1"<<"   "<<"2"<<"   "<<"3"<<"   "<<"4"<<"  "<<endl;
    std::cout << "  -----------------" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << c++<<" "<< " | ";
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != nullptr) {
                grid[i][j].display();
            } else {
                std::cout << " ";
            }
            std::cout << " | ";
        }
        std::cout << std::endl;
        std::cout << "  -----------------" << std::endl;
    }
}



void Deck::flipCard(int row, int col, bool faceUp) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4 && grid[row][col] != nullptr) {
        if (faceUp) {
            grid[row][col].reveal();
        } else {
            grid[row][col].hide();
        }
    }
}

Card* Deck::getCard(int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        return &grid[row][col];
    }
    return nullptr;
}

Game::~Game() {
}
void Game::playTurn() {
    displayPlayerInfo(); // Display the current player's name and score
    Player& current = (currentPlayer == 1) ? player1 : player2;
    std::cout << "\n" << current.getName() << "'s turn!" << std::endl;
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}
void Deck::removeoneCard(int row, int col) {
    if (row >= 0 && row < 4 && col >= 0 && col < 4) {
        grid[row][col] = nullptr;
    }
}
void Game::playTwice() {
    for (int i = 0; i < 1; ++i) {
        Player& current = (currentPlayer == 1) ? player1 : player2;
        int row1 = 0, col1=0;
        int row2, col2;

        while (true) {
            displayPlayerInfo();
            try {
                std::cout << "Enter row and column for the first card: ";
                std::cin >> row1 >> col1;
                if (row1 < 1 || row1 > 4 || col1 < 1 || col1 > 4) {
                    throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
                }

                std::cout << "Enter row and column for the second card: ";
                std::cin >> row2 >> col2;
                if (row2 < 1 || row2 > 4 || col2 < 1 || col2 > 4) {
                    throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
                }

                Card* card1 = deck.getCard(row1 - 1, col1 - 1);
                Card* card2 = deck.getCard(row2 - 1, col2 - 1);

                if (card1 == nullptr || card2 == nullptr) {
                    std::cout << "One or both of the selected cards have been removed. Please try again." << std::endl;
                    continue;
                }

                if (card1->getIsfaceUp()) {
                    std::cout << "The first card is already face up. Please try again." << std::endl;
                    continue;
                }

                if (card2->getIsfaceUp()) {
                    std::cout << "The second card is already face up. Please try again." << std::endl;
                    continue;
                }

                if (row1 == row2 && col1 == col2) {
                    std::cout << "You have selected the same card twice. Please try again." << std::endl;
                    continue;
                }

                break; // Valid input, exit the loop
            } catch (const std::out_of_range& e) {
                std::cout << e.what() << std::endl;
            } catch (const std::exception& e) {
                std::cout << "An error occurred: " << e.what() << std::endl;
            }
        }

        // Flip the first and second cards face-up
        deck.flipCard(row1 - 1, col1 - 1, true);
        deck.flipCard(row2 - 1, col2 - 1, true);
        deck.displayGrid();

        Card* card1 = deck.getCard(row1 - 1, col1 - 1);
        Card* card2 = deck.getCard(row2 - 1, col2 - 1);

        if (card1->getValue() == card2->getValue()) {
            if ((card1->getValue()==7 && (card2->getValue()>0 ||card2->getValue()<=6  ) ) && (card2->getValue()==7&& (card2->getValue()>0 ||card2->getValue()<=6  )) ) {
                int choice;
                std::cout << "You have two bonus cards! Choose an option:\n1. +2 points\n2. +1 point and take another turn\n";
                std::cin >> choice;
                if (choice == 1) {
                    current.addScore(2);
                    std::cout << "Bonus! +2 points." << std::endl;
                } else {
                    current.addScore(1);
                    std::cout << "Bonus! +1 point. Take another turn." << std::endl;
                    deck.removeCards(card1, card2);
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    return;
                }
                deck.removeCards(card1, card2);
            } else if ((card1->getValue()==8 && (card2->getValue()>0 ||card2->getValue()<=6  ))  && ( card2->getValue()==8 && (card2->getValue()>0 ||card2->getValue()<=6  )))  {
                int choice;
                std::cout << "You have two penalty cards! Choose an option:\n1. Lose 2 points\n2. Lose 1 point and skip the next turn\n";
                std::cin >> choice;
                if (choice == 1) {
                    current.deduceScore(2);
                    std::cout << "Penalty! -2 points." << std::endl;

                } else {
                    current.deduceScore(1);
                    std::cout << "Penalty! -1 point. Skip the next turn." << std::endl;
                    deck.removeCards(card1, card2);
                    currentPlayer = (currentPlayer == 1) ? 2 : 1;
                    playTwice();
                    return;
                }
                deck.removeCards(card1, card2);

            } else {
                current.addScore(1);  // Standard card match, add 1 point
                std::cout << "Standard match! +1 point." << std::endl;
            }
            deck.removeCards(card1, card2);
        } else {
            if ((card1->getValue()==7  && card2->getValue()==8 ) ||
                (card1->getValue()==8  && card2->getValue()==7 )) {
                std::cout << "Bonus and Penalty cards revealed. No effect on score." << std::endl;
                deck.removeCards(card1, card2);
                }else if ((card1->getValue() == 7 && (card2->getValue() > 0 && card2->getValue() <= 6)) ||
             (card2->getValue() == 7 && (card1->getValue() > 0 && card1->getValue() <= 6))) {
                    current.addScore(1);
                    std::cout << "Bonus! +1 point." << std::endl;
                    if (card1->getValue() == 7) {
                        deck.removeoneCard(row1-1, col1-1);
                        card2->hide();
                    } else {

                        deck.removeoneCard(row2-1, col2-1);
                        card1->hide();
                    }
             } else if ((card1->getValue() == 8 && (card2->getValue() > 0 && card2->getValue() <= 6)) ||
                        (card2->getValue() == 8 && (card1->getValue() > 0 && card1->getValue() <= 6))) {
                 current.deduceScore(1);
                 std::cout << "Penalty! -1 point." << std::endl;
                 if (card1->getValue() == 8) {
                     deck.removeoneCard(row1-1, col1-1);
                     card2->hide();
                 } else {

                     deck.removeoneCard(row2-1, col2-1);
                     card1->hide();
                 }
               }else {
                   std::cout << "Not a match!" << std::endl;
                   deck.flipCard(row1 - 1, col1 - 1, false);
                   deck.flipCard(row2 - 1, col2 - 1, false);
                }
        }
        std::cout << "Press Enter to hide the cards and switch turns...";
        std::cin.ignore();
        std::cin.get();
    }
}

void Game::scoring() {
    Player& current = (currentPlayer == 1) ? player1 : player2;
    int row1 = 0, col1=0;
    int row2, col2;

    while (true) {
        try {
            std::cout << "Enter row and column for the first card: ";
            std::cin >> row1 >> col1;
            if (row1 < 1 || row1 > 4 || col1 < 1 || col1 > 4) {
                throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
            }

            std::cout << "Enter row and column for the second card: ";
            std::cin >> row2 >> col2;
            if (row2 < 1 || row2 > 4 || col2 < 1 || col2 > 4) {
                throw std::out_of_range("Invalid input. Row and column values must be between 1 and 4.");
            }

            Card* card1 = deck.getCard(row1 - 1, col1 - 1);
            Card* card2 = deck.getCard(row2 - 1, col2 - 1);

            if (card1 == nullptr || card2 == nullptr) {
                std::cout << "One or both of the selected cards have been removed. Please try again." << std::endl;
                continue;
            }

            if (card1->getIsfaceUp()) {
                std::cout << "The first card is already face up. Please try again." << std::endl;
                continue;
            }

            if (card2->getIsfaceUp()) {
                std::cout << "The second card is already face up. Please try again." << std::endl;
                continue;
            }

            if (row1 == row2 && col1 == col2) {
                std::cout << "You have selected the same card twice. Please try again." << std::endl;
                continue;
            }

            break; // Valid input, exit the loop
        } catch (const std::out_of_range& e) {
            std::cout << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cout << "An error occurred: " << e.what() << std::endl;
        }
    }

    // Flip the first and second cards face-up
    deck.flipCard(row1 - 1, col1 - 1, true);
    deck.flipCard(row2 - 1, col2 - 1, true);
    deck.displayGrid();

    Card* card1 = deck.getCard(row1 - 1, col1 - 1);
    Card* card2 = deck.getCard(row2 - 1, col2 - 1);

    if (card1->getValue() == card2->getValue()) {
        if ((card1->getValue()==7  ) && (card2->getValue()==7) ) {
            int choice;
            std::cout << "You have two bonus cards! Choose an option:\n1. +2 points\n2. +1 point and take another turn\n";
            std::cin >> choice;
            if (choice == 1) {
                current.addScore(2);
                std::cout << "Bonus! +2 points." << std::endl;
            } else {
                current.addScore(1);
                std::cout << "Bonus! +1 point. Take another turn." << std::endl;
                deck.removeCards(card1, card2);
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
                return;
            }
            deck.removeCards(card1, card2);
        } else if ((card1->getValue()==8 )  && ( card2->getValue()==8 ))  {
            int choice;
            std::cout << "You have two penalty cards! Choose an option:\n1. Lose 2 points\n2. Lose 1 point and skip the next turn\n";
            std::cin >> choice;
            if (choice == 1) {
                current.deduceScore(2);
                std::cout << "Penalty! -2 points." << std::endl;

            } else {
                current.deduceScore(1);
                std::cout << "Penalty! -1 point. Skip the next turn." << std::endl;
                deck.removeCards(card1, card2);
                currentPlayer = (currentPlayer == 1) ? 2 : 1;
                playTwice();
                return;
            }
            deck.removeCards(card1, card2);

        } else {
            current.addScore(1);  // Standard card match, add 1 point
            std::cout << "Standard match! +1 point." << std::endl;
        }
        deck.removeCards(card1, card2);
    } else {
        if ((card1->getValue()==7  && card2->getValue()==8 ) ||
            (card1->getValue()==8  && card2->getValue()==7 )) {
            std::cout << "Bonus and Penalty cards revealed. No effect on score." << std::endl;
            deck.removeCards(card1, card2);
            }else if ((card1->getValue() == 7 && (card2->getValue() > 0 && card2->getValue() <= 6)) ||
         (card2->getValue() == 7 && (card1->getValue() > 0 && card1->getValue() <= 6))) {
                current.addScore(1);
                std::cout << "Bonus! +1 point." << std::endl;
                if (card1->getValue() == 7) {
                    deck.removeoneCard(row1-1, col1-1);
                    card2->hide();
                } else {

                    deck.removeoneCard(row2-1, col2-1);
                    card1->hide();
                }
         } else if ((card1->getValue() == 8 && (card2->getValue() > 0 && card2->getValue() <= 6)) ||
                    (card2->getValue() == 8 && (card1->getValue() > 0 && card1->getValue() <= 6))) {
             current.deduceScore(1);
             std::cout << "Penalty! -1 point." << std::endl;
             if (card1->getValue() == 8) {
                 deck.removeoneCard(row1-1, col1-1);
                 card2->hide();
             } else {

                 deck.removeoneCard(row2-1, col2-1);
                 card1->hide();
             }
           }else {
            std::cout << "Not a match!" << std::endl;
            deck.flipCard(row1 - 1, col1 - 1, false);
            deck.flipCard(row2 - 1, col2 - 1, false);
        }
    }

    // Prompt the current player to press Enter to hide the cards and switch turns
    std::cout << "Press Enter to hide the cards and switch turns...";
    std::cin.ignore();
    std::cin.get();
    currentPlayer = (currentPlayer == 1) ? 2 : 1;

    deck.displayGrid();




}
void Game::initializeGame() {
    std::cout << "Welcome to the 2D Card Matching Game!" << std::endl;

    std::cout << "Shuffling cards..." << std::endl;
    deck.shuffle();

    std::cout << "\nInitial Card Grid:" << std::endl;
    deck.displayGrid();


}


void Game::displayScores() {
    player1.displayScore();
    player2.displayScore();
}

Game::Game() {
   string x,y;
    cout<<"Enter the name of the first player: ";
    cin>>x;
    player1.setName(x);
    player1.setScore(0);
    cout<<"Enter the name of the second player: ";
    cin>>y;
    player2.setName(y);
    player2.setScore(0);
}
bool Deck::allCardsFlipped() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (grid[i][j] != nullptr && !grid[i][j].getIsFaceUp()) {
                return false;
            }
        }
    }
    return true;
}
void Game::start() {
    initializeGame();

    while (true) {
        displayPlayerInfo();
        scoring();
        if (deck.allCardsFlipped()) {
            std::cout << "All cards have been matched. The game has ended!" << std::endl;
            break;
        }
    }
    displayScores();
    if (player1.getScore() > player2.getScore()) {
        std::cout << player1.getName() << " wins with a score of " << player1.getScore() << "!" << std::endl;
    } else if (player1.getScore() < player2.getScore()) {
        std::cout << player2.getName() << " wins with a score of " << player2.getScore() << "!" << std::endl;
    } else {
        std::cout << "It's a tie! Both players have a score of " << player1.getScore() << "." << std::endl;
    }
}

void Game::displayPlayerInfo() {
    std::cout << "Player 1: " << player1.getName() << " - Score: " << player1.getScore() << std::endl;
    std::cout << "Player 2: " << player2.getName() << " - Score: " << player2.getScore() << std::endl;
    std::cout << "Current turn: " << (currentPlayer == 1 ? player1.getName() : player2.getName()) << std::endl;
}




int main() {

    Game game;
    game.start();
    return 0;
}