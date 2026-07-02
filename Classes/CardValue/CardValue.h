#include "../../headers/Includes.h"

enum class CardValue
{
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

std::string cardValueToStr(const CardValue& cardValue);
