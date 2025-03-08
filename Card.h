#ifndef CARD_H
#define CARD_H
class Card {
public:
    int value;
    bool isFaceUp;

    Card();
    Card(int value, bool isFaceUp);
    virtual ~Card();
    void setValue(int v);
    void setIsfaceUp(bool f);
    int getValue();
    bool getIsfaceUp();
    virtual void display();

    void reveal();
    void hide();
    bool getIsFaceUp();
    int getValue()const ;


    Card &operator=(nullptr_t null);

    bool operator!=(nullptr_t null) const;
};


#endif
