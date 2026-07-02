#pragma once
#include "Definitions.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void goToXY(int x, int y) {
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console, CursorPosition);
}

void setCursor(bool visible, DWORD size) {
    if (size == 0)
        size = 20;

    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = size;
    SetConsoleCursorInfo(console, &lpCursor);
}

void setPrintColor(SUIT suit)
{
    const int BACKGROUND_WHITE = 0x00F0; // White background
    const int BACKGROUND_BLACK = 0x0000; // Black background
    switch (suit)
    {
    case SUIT::SIRT:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        break;
    case SUIT::XACH:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        break;
    case SUIT::QYAP:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
        break;
    case SUIT::GHAR:
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
        break;
    }
}



void printTalkFrame(std::size_t talk = 8)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    setCursor(0, 0);
    srand((unsigned)time(NULL));
    if (talk >= 10)
    {
        goToXY(27, 12); std::wcout << "+-------------------------------------------+";
        goToXY(27, 13); std::wcout << "|    -    |     " << talk << "     |    +    |     " << "K    |";
        goToXY(27, 14); std::wcout << "+-------------------------------------------+";
        goToXY(27, 15); std::wcout << "|   " << L'\u2660' << "   |   " << L'\u2665' << "   |   " << L'\u2663' << "   |   " << L'\u2666' << "   |  " << "A" << "  |  " << "B" << "  |";
        goToXY(27, 16); std::wcout << "+-------------------------------------------+";
        goToXY(27, 17); std::wcout << "| Xosel | Quansh | Lavem | Vzova | Spasumem |";
        goToXY(27, 18); std::wcout << "+-------------------------------------------+";
    }          
    else       
    {          
        goToXY(27, 12); std::wcout << "+-------------------------------------------+";
        goToXY(27, 13); std::wcout << "|    -    |     " << talk << "     |    +    |     " << "K     |";
        goToXY(27, 14); std::wcout << "+-------------------------------------------+";
        goToXY(27, 15); std::wcout << "|   " << L'\u2660' << "   |   " << L'\u2665' << "   |   " << L'\u2663' << "   |   " << L'\u2666' << "   |  " << "A" << "  |  " << "B" << "  |";
        goToXY(27, 16); std::wcout << "+-------------------------------------------+";
        goToXY(27, 17); std::wcout << "| Xosel | Quansh | Lavem | Vzova | Spasumem |";
        goToXY(27, 18); std::wcout << "+-------------------------------------------+";
    }
    _setmode(_fileno(stdout), _O_TEXT);

}

