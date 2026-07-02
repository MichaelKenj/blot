#pragma once
#include "Player.h"
#include "printHelperFunctions.h"


class Game
{
private:
    Kalod m_kalod;

    // Player0 - is user, pair is Player2
    std::vector<Player> m_players;

    Board m_board;
    
    std::size_t m_width;
    std::size_t m_height;

    std::size_t m_dealer; // index of player-dealer
public:
    Game()
    {
        srand(time(NULL));

        configureBoard();

        m_height = m_board.size();
        m_width = m_board[0].size();

        shuffleCards();

        putCardsOnBoard();
        m_dealer = pickRandomDealer();
        printBoard(); 
        printTalkFrame();
    }

    void play()
    {

    }

    void shuffleCards()
    {
        m_kalod = Kalod();

        m_players.resize(4);
        for (std::size_t i = 0; i < 4; ++i)
            for (std::size_t j = 0; j < 8; ++j)
                m_players[i].addCardToPlayer(m_kalod.pickRandomCard());
    }

    void talk()
    {
        if (m_dealer == 3)
        {
            m_dealer == 0;
        }
        std::size_t nextPlayer = ++m_dealer;
        do
        {
            
        } while (!isConfirmed());
    }

    void showPlayersCards() const
    {
        int i = 0;
        for (const auto& player : m_players)
        {
            std::wcout << "Player" << i++ << ": ";
            player.showCards();
            std::wcout << '\n';
        }
    }

    void printBoard() const
    {
        _setmode(_fileno(stdout), _O_U16TEXT); // Set console mode for Unicode output
        for (const auto& row : m_board)
        {
            for (const auto& cell : row)
            {
                switch (cell)
                {
                case L'\u2665':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    break;
                case L'\u2663':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                    break;
                case L'\u2666':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                    break;
                case L'\u2660':
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
                    break;
                }
                std::wcout << std::setw(2) << cell;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            std::wcout << '\n'; // End of row
        }
        _setmode(_fileno(stdout), _O_TEXT); // Reset console mode
    }
    
    void configureBoard()
    {
        m_board.resize(30, std::vector<wchar_t>(50, ' '));

        for (int i = 0; i < m_board.size(); ++i)
        {
            m_board[i][0] = L'|';
            m_board[i][m_board[i].size() - 1] = L'|'; 
        }
        for (int j = 0; j < m_board[0].size(); ++j)
        {
            m_board[0][j] = L'-'; 
            m_board[m_board.size() - 1][j] = L'-'; 
        }
        m_board[m_board.size() - 1][m_board[0].size() - 1] = L'|';
    }

    void putCardsOnBoard()
    {
        std::size_t startIndexInWidth = m_width / 2 - 12;
        for (std::size_t i = 0; i < 8; ++i)
        {
            const wchar_t* cardTypeString = m_players[0].getCardAtIndex(i).getCardTypeInChar();
            m_board[m_board.size() - 2][startIndexInWidth] = m_players[0].getCardAtIndex(i).getSuitInChar()[0];
            for (std::size_t j = 0; j < wcslen(cardTypeString); ++j)
            {
                m_board[m_board.size() - 2][startIndexInWidth + 1] = m_players[0].getCardAtIndex(i).getCardTypeInChar()[j];
                if (wcslen(cardTypeString) == 2)
                    ++startIndexInWidth;
            }
            if (wcslen(cardTypeString) == 2)
                --startIndexInWidth;
            startIndexInWidth += 3;
        }
        startIndexInWidth = (m_width - 1) / 2 - 8;

        for (std::size_t i = 0; i < 8; ++i)
        {
            m_board[1][startIndexInWidth += 2] = 'X';
        }

        std::size_t startIndexInHeight = (m_height - 1) / 2 - 8;

        for (std::size_t i = 0; i < 8; ++i)
        {
            m_board[startIndexInHeight += 2][2] = 'X';
        }

        startIndexInHeight = (m_height - 1) / 2 - 8;

        for (std::size_t i = 0; i < 8; ++i)
        {
            m_board[startIndexInHeight += 2][m_board[0].size() - 2] = 'X';
        }
    }

    std::size_t pickRandomDealer() const
    {
        return generateRandomNumber(0, 3);
    }

    bool isConfirmed() const
    {
        for (const auto& player : m_players)
            if (player.getTalkState() != TalkState::VZOVA)
                return false;
        
        return true;
    }
};