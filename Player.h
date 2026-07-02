#pragma once
#include "Card.h"

class Player
{
private:
	std::set<Card, Compare> m_cards;
	TalkValue m_talkValue;
	TalkState m_talkState;
public:
	void addCardToPlayer(const Card& card)
	{
		m_cards.insert(card);
	}

	void showCards() const
	{
		for (const auto& card : m_cards)
		{
			card.print();
			std::wcout << " ";
		}
	}

	Card getCardAtIndex(std::size_t index) const
	{
		auto it = m_cards.begin();
		for (std::size_t i = 0; i < index; ++i)
			++it;
		return *it;
	}

	auto getTalkValue() const
	{
		return m_talkValue;
	}

	void setTalkValue()
	{

	}

	auto getTalkState() const
	{
		return m_talkState;
	}

	void setTalkState(TalkState state)
	{
		m_talkState = state;
	}
};
