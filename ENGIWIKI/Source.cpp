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
	cout << "Играть вдвоем";
	gotoXY(40, 12);
	cout << "Играть с компьютером";
	gotoXY(40, 14);
	cout << "Конец игры";
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
		cout << "Игрок X выиграл!";
	}
	else cout << "Игрок 0 выиграл!";
}

void gamecomputer()
{
	system("cls");
	cout << "Выберете, кем вы будете играть: 0 или Х: ";
	char key = _getch();

	if (key == 'x') key = 'X';
	else key = '0';
	char ai_char;
	if (key == 'X') ai_char = '0';
	else ai_char = 'X';
	board ai_board;
	ai_board.init();
	while (true)
	{
		if (ai_board.board_is_full())
			ai_board.init();
		if (!ai_board.win())
			ai_board.input(key);
		else break;
		if (!ai_board.win())
		{
			if (ai_board.is_empty_position(1, 1)) ai_board.setChar(1, 1, ai_char);
			else if (ai_board.is_empty_position(0, 0)) ai_board.setChar(0, 0, ai_char);
			else if (ai_board.is_empty_position(2, 2)) ai_board.setChar(2, 2, ai_char);
			else if (ai_board.is_empty_position(0, 2)) ai_board.setChar(0, 2, ai_char);
			else if (ai_board.is_empty_position(2, 0)) ai_board.setChar(2, 0, ai_char);
			else if (ai_board.is_empty_position(1, 0)) ai_board.setChar(1, 0, ai_char);
			else if (ai_board.is_empty_position(1, 2)) ai_board.setChar(1, 2, ai_char);
			else if (ai_board.is_empty_position(0, 1)) ai_board.setChar(0, 1, ai_char);
			else if (ai_board.is_empty_position(2, 0)) ai_board.setChar(2, 0, ai_char);
		}
		else break;
	}
	end_game(ai_board);
	_getch();
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
