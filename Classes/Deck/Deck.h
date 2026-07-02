#include "../Card/Card.h"
#include "../../headers/Includes.h"

class Deck
{
public:
    Deck();

    void fill();
    void shuffle();

    void printDeck() const;
private:
    std::vector<Card> _deck;
};