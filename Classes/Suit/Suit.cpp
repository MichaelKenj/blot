#include "Suit.h"

std::string suitToStr(const Suit& suit)
{
	switch (suit)
	{
	case Suit::SPADES:
		return std::string("Ghar");
	case Suit::HEARTS:
		return std::string("Sirt");
	case Suit::DIAMONDS:
		return std::string("Qyap");
	case Suit::CLUBS:
		return std::string("Xach");
	}
}