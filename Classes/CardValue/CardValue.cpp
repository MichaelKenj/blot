#include "CardValue.h"

std::string cardValueToStr(const CardValue& cardValue)
{
    switch (cardValue)
    {
    case CardValue::SEVEN:
        return std::string("7");
    case CardValue::EIGHT:
        return std::string("8");
    case CardValue::NINE:
        return std::string("9");
    case CardValue::TEN:
        return std::string("10");
    case CardValue::JACK:
        return std::string("J");
    case CardValue::QUEEN:
        return std::string("Q");
    case CardValue::KING:
        return std::string("K");
    case CardValue::ACE:
        return std::string("A");
    }
}