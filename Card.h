#pragma once
#include "Definitions.h"
#include "Functional.h"
#include "printHelperFunctions.h"

struct Card
{
private:
	SUIT m_suit;
	CARD_TYPE m_cardType;
public:
	Card() = default;

	Card(SUIT suit, CARD_TYPE cardType) : m_suit(suit), m_cardType(cardType)
	{}

	void print() const
	{
		_setmode(_fileno(stdout), _O_U16TEXT);
		setPrintColor(m_suit);
		switch (m_suit)
		{
		case SUIT::SIRT:
			std::wcout <<  L"\u2665";
			break;
		case SUIT::XACH:
			std::wcout << L"\u2663";
			break;
		case SUIT::QYAP:
			std::wcout << L"\u2666";
			break;
		case SUIT::GHAR:
			std::wcout << L"\u2660";
			break;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		switch (m_cardType)
		{
		case CARD_TYPE::SEVEN:
			std::wcout << "7";
			break;
		case CARD_TYPE::EIGHT:
			std::wcout << "8";
			break;
		case CARD_TYPE::NINE:
			std::wcout << "9";
			break;
		case CARD_TYPE::TEN:
			std::wcout << "10";
			break;
		case CARD_TYPE::JACK:
			std::wcout << "J";
			break;
		case CARD_TYPE::QUEEN:
			std::wcout << "Q";
			break;
		case CARD_TYPE::KING:
			std::wcout << "K";
			break;
		case CARD_TYPE::ACE:
			std::wcout << "A";
			break;
		}
	}

	auto getSuitInChar() const
	{
		switch (m_suit)
		{
		case SUIT::SIRT:
			return L"\u2665";
			break;
		case SUIT::XACH:
			return L"\u2663";
			break;
		case SUIT::QYAP:
			return L"\u2666";
			break;
		case SUIT::GHAR:
			return L"\u2660";
			break;
		}
	}

	auto getCardTypeInChar() const
	{
		switch (m_cardType)
		{
		case CARD_TYPE::SEVEN:
			return L"7";
			break;
		case CARD_TYPE::EIGHT:
			return L"8";
			break;
		case CARD_TYPE::NINE:
			return L"9";
			break;
		case CARD_TYPE::TEN:
			return L"10";
			break;
		case CARD_TYPE::JACK:
			return L"J";
			break;
		case CARD_TYPE::QUEEN:
			return L"Q";
			break;
		case CARD_TYPE::KING:
			return L"K";
			break;
		case CARD_TYPE::ACE:
			return L"A";
			break;
		}
	}

	auto getSuit() const
	{
		return m_suit;
	}

	auto getCardType() const
	{
		return m_cardType;
	}
};

struct Compare
{
	bool operator()(const Card& r, const Card& l) const
	{
		if (r.getSuit() != l.getSuit())
		{
			auto it_r = std::find(vecSuit.begin(), vecSuit.end(), r.getSuit());
			auto it_l = std::find(vecSuit.begin(), vecSuit.end(), l.getSuit());
			return it_r < it_l;
		}
		else
		{
			auto it_r = std::find(vecCardType.begin(), vecCardType.end(), r.getCardType());
			auto it_l = std::find(vecCardType.begin(), vecCardType.end(), l.getCardType());
			return it_r < it_l;
		}
	}
};

class Kalod
{
private:
	std::set<Card, Compare> m_kalod;
public:
	Kalod()
	{
		for (const auto& suit : vecSuit)
		{
			for (const auto& type : vecCardType)
			{
				m_kalod.insert(Card(suit, type));
			}
		}
	}

	void removeCard(const Card& card)
	{
		m_kalod.erase(card);
	}

	Card pickRandomCard()
	{
		Card card;
		do {
			int randomIndex = generateRandomNumber(0, 3);
			SUIT randomSuit = static_cast<SUIT>(randomIndex);
			randomIndex = generateRandomNumber(0, 7);
			CARD_TYPE randomCardType = static_cast<CARD_TYPE>(randomIndex);
			card = Card(randomSuit, randomCardType);
		} while (m_kalod.find(card) == m_kalod.end());
		m_kalod.erase(card);

		return card;
	}
};