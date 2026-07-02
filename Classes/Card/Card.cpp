#include "Card.h"

Card::Card(const Suit& suit, const CardValue& cardValue) : _suit(suit), _cardValue(cardValue)
{
}

Suit Card::getSuit() const
{
    return _suit;
}

CardValue Card::getValue() const
{
    return _cardValue;
}

void Card::setSuit(const Suit& suit)
{
    _suit = suit;
}

void Card::setValue(const CardValue& cardValue)
{
    _cardValue = cardValue;
}

void Card::printInfo() const
{
    std::cout << suitToStr(_suit) << cardValueToStr(_cardValue);
}

bool Card::operator==(const Card& other) const
{
    return _suit == other.getSuit() && _cardValue == other.getValue();
}