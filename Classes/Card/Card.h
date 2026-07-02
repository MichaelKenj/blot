#include "../../headers/Includes.h"
#include "../Suit/Suit.h"
#include "../CardValue/CardValue.h"

class Card
{
public:
    Card(const Suit& suit, const CardValue& cardValue);

    Suit getSuit() const;
    CardValue getValue() const;

    void setSuit(const Suit& suit);
    void setValue(const CardValue& cardValue);

    void printInfo() const;

    bool operator==(const Card& other) const;

private:
    Suit _suit;
    CardValue _cardValue;
};