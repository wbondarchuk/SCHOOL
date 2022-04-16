#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <cstdlib>
#include "board.h"

void ShowMenu();
void draw_pointer(int coord);
void end_game(board b);
void gameplayer();
void gamecomputer();


int main()
{
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(StdOut, &info);
	setlocale(LC_ALL, "rus");
	ShowMenu();
	KeyValue key;
	int n = 1;
	while (true) {
		switch (n) {
		case 1:
			draw_pointer(10);
			break;
		case 2:
			draw_pointer(12);
			break;
		case 3:
			draw_pointer(14);
			break;
		}
		int(key) = _getch();
		if (key == LEFT) {
			if (n == 1) n = 3;
			else n--;
		}
		if (key == DOWN) {
			if (n == 3) n = 1;
			else n++;
		}
		if (key == UP) {
			if (n == 1) n = 3;
			else n--;
		}
		if (key == ENTER) {
			switch (n) {
			case 3:
				return 0;
			case 1:
				gameplayer();
				break;
			case 2:
				gamecomputer();
				break;
			}
			system("cls");
			ShowMenu();
		}
		for (int i = 10; i <= 16; i += 2) {
			gotoXY(35, i);
			cout << " ";
			gotoXY(72, i);
			cout << " ";
		}
	}
}

void ShowMenu()
{
	gotoXY(40, 10);
	cout << "Èãðàòü âäâîåì";
	gotoXY(40, 12);
	cout << "Èãðàòü ñ êîìïüþòåðîì";
	gotoXY(40, 14);
	cout << "Êîíåö èãðû";
}
void draw_pointer(int coord)
{
	gotoXY(35, coord);
	cout << ">";
	gotoXY(72, coord);
	cout << "<";
}
void end_game(board b)
{
	system("cls");
	b.ShowBoard(50);
	b.ShowValues(52, 57, 62);
	gotoXY(53, 12);
	if (b.win() == 1)
	{
		cout << "Èãðîê X âûèãðàë!";
	}
	else cout << "Èãðîê 0 âûèãðàë!";
}

void gameplayer()
{
	board Board;
	Board.init();
	while (true)
	{
		if (!Board.win()) {
			if (Board.board_is_full()) Board.init();
			Board.input('X');
		}
		else break;
		if (!Board.win()) {
			if (Board.board_is_full()) Board.init();
			Board.input('0');
		}
		else break;
	}
	end_game(Board);
	_getch();
}
