#pragma once
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>
#include <print>
#include <iomanip>
#include <sstream>


struct TalkValue
{
	SUIT m_suit;
	std::size_t m_value;
	TalkValue() = default;
	
	TalkValue(SUIT suit, std::size_t value) : m_suit(suit), m_value(value)
	{}
};

// Generates random number in [x,y]
std::size_t generateRandomNumber(std::size_t x, std::size_t y)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<std::size_t> dis(x, y);
	return dis(gen);
}

std::map<SUIT, char> mapSuit
{
	{SUIT::SIRT, 'S'},
	{SUIT::XACH, 'X'},
	{SUIT::QYAP, 'Q'},
	{SUIT::GHAR, 'G'},
};

std::map<CARD_TYPE, std::string> mapCardType
{
	{CARD_TYPE::SEVEN, "7"},
	{CARD_TYPE::EIGHT, "8"},
	{CARD_TYPE::NINE, "9"},
	{CARD_TYPE::TEN, "10"},
	{CARD_TYPE::JACK, "J"},
	{CARD_TYPE::QUEEN, "Q"},
	{CARD_TYPE::KING, "K"},
	{CARD_TYPE::ACE, "A"}
};

const std::vector<SUIT> vecSuit
{ 
	SUIT::SIRT,
	SUIT::XACH, 
	SUIT::QYAP, 
	SUIT::GHAR 
};

const std::vector<CARD_TYPE> vecCardType
{
	CARD_TYPE::SEVEN,
	CARD_TYPE::EIGHT,
	CARD_TYPE::NINE,
	CARD_TYPE::TEN,
	CARD_TYPE::JACK,
	CARD_TYPE::QUEEN,
	CARD_TYPE::KING,
	CARD_TYPE::ACE
};
std::string identifyCardType(CARD_TYPE suit)
{
	switch (suit)
	{
	case CARD_TYPE::SEVEN:
		return "7";
		break;
	case CARD_TYPE::EIGHT:
		return "8";
		break;
	case CARD_TYPE::NINE:
		return "9";
		break;
	case CARD_TYPE::TEN:
		return "10";
		break;
	case CARD_TYPE::JACK:
		return "J";
		break;
	case CARD_TYPE::QUEEN:
		return "Q";
		break;
	case CARD_TYPE::KING:
		return "K";
		break;
	case CARD_TYPE::ACE:
		return "A";
		break;
	}
}