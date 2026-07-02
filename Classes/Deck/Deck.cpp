#include "Deck.h"

Deck::Deck()
{
    _deck.reserve(32);
    //fill();
    shuffle();
}

void Deck::fill()
{
    const std::vector<Suit> suits{
        Suit::SPADES,
        Suit::HEARTS,
        Suit::DIAMONDS,
        Suit::CLUBS
    };

    const std::vector<CardValue> values{
        CardValue::SEVEN,
        CardValue::EIGHT,
        CardValue::NINE,
        CardValue::TEN,
        CardValue::JACK,
        CardValue::QUEEN,
        CardValue::KING,
        CardValue::ACE
    };

    for (Suit suit : suits)
    {
        for(CardValue cardValue : values)
        {
            _deck.emplace_back(suit, cardValue);
        }
    }
}

void Deck::shuffle()
{
    srand(time(NULL));

    const std::vector<Suit> suits{
        Suit::SPADES,
        Suit::HEARTS,
        Suit::DIAMONDS,
        Suit::CLUBS
    };

    const std::vector<CardValue> values{
        CardValue::SEVEN,
        CardValue::EIGHT,
        CardValue::NINE,
        CardValue::TEN,
        CardValue::JACK,
        CardValue::QUEEN,
        CardValue::KING,
        CardValue::ACE
    };

    while(_deck.size() != 32)
    {
        std::size_t randomSuit = rand() % 4;
        std::size_t randomValue = rand() % 8;
        Card randomCard(suits[randomSuit], values[randomValue]);
        auto isCardAlreadyInDeck = std::find(_deck.begin(), _deck.end(), randomCard);
        if(isCardAlreadyInDeck == _deck.end())
        {
            _deck.emplace_back(randomCard);
        }
    }
}

void Deck::printDeck() const
{
    for(Card card : _deck)
    {
        card.printInfo();
        std::cout << " ";
    }
}