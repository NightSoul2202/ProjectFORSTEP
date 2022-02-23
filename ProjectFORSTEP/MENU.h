#pragma once
#include<windows.h>
#include<vector>
#include<iostream>
#include<string>
#include<conio.h>
#include <ctime>

using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

enum ConsoleColor
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

struct Menu
{
	int select_vertical(vector <string> menu)
	{
		char c;
		int pos = 0;
		do
		{
			for (int i = 0; i < menu.size(); i++)
			{
				if (i == pos)
				{
					SetColor(0, 15);
					gotoxy(25, 12 - menu.size() / 2 + i);
					cout << "                             ";
					int len = menu[i].length();
					gotoxy(40 - len / 2, 12 - menu.size() / 2 + i);
					cout << menu[i] << endl;
					SetColor(15, 0);
				}
				else
				{
					SetColor(15, 0);
					gotoxy(25, 12 - menu.size() / 2 + i);
					cout << "                             ";
					int len = menu[i].length();
					gotoxy(40 - len / 2, 12 - menu.size() / 2 + i);
					cout << menu[i] << endl;
					SetColor(0, 15);
				}

			}
			c = _getch();
			switch (c)
			{
			case 72: //�����
				if (pos > 0)
					pos--;
				break;
			case 80: // ����
				if (pos < menu.size() - 1)
					pos++;
				break;
			case 13:
				break;
			default:
				break;
			}
		} while (c != 13);
		SetColor(7, 0);
		return pos;
	}

	int select_gorizontal(vector<string> menu)
	{
		int max_len = 0;
		for (int i = 0; i < menu.size(); i++)
			max_len += menu[i].length();
		if (max_len > 80 - menu.size() - 1)
			int a = 1;/////////
	}
};




