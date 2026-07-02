#pragma once
#include "../../headers/Includes.h"

enum class Suit
{ 
	SPADES, // Ghar
	HEARTS, // Sirt
	DIAMONDS, // Qyap
	CLUBS // Xach
};

std::string suitToStr(const Suit& suit);