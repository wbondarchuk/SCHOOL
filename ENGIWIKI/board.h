#pragma once
using namespace std;

enum KeyValue
{
	ENTER = 13,
	UP = 72,
	DOWN = 80,     
	LEFT = 75,
	RIGHT = 77,
};

void gotoXY(int x, int y) {
	COORD c = { x,y };
	HANDLE StdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(StdOut, c);
}

class board
{
	void clear_pos(int i, int j)
	{
		gotoXY(i, j);
		cout << " ";
	}
	char symbols[3][3];

	int current_x = 0;
	int current_y = 0;
public:
	void init() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				symbols[i][j] = ' ';
			}
		}
	}


	bool board_is_full() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (symbols[i][j] == ' ') return false;
			}
		}
		return true;
	}
	bool is_empty_position(int a, int b)
	{
		return symbols[a][b] == ' ';
	}
	void resetXY() {
		current_x = 0;
		current_y = 0;
	}
	void setChar(int a, int b, char s)
	{
		symbols[a][b] = s;
	}

	void ShowBoard(int position) {
		gotoXY(position, 3);
		cout << "_______________";
		gotoXY(position, 4);
		cout << "|    |    |    |";
		gotoXY(position, 5);
		cout << "|____|____|____|";

		gotoXY(position, 6);
		cout << "|    |    |    |";
		gotoXY(position, 7);
		cout << "|____|____|____|";

		gotoXY(position, 8);
		cout << "|    |    |    |";
		gotoXY(position, 9);
		cout << "|____|____|____|";
	}

	void ShowValues(int a, int b, int c)
	{
		gotoXY(a, 4); cout << symbols[0][0];
		gotoXY(b, 4); cout << symbols[0][1];
		gotoXY(c, 4); cout << symbols[0][2];

		gotoXY(a, 6); cout << symbols[1][0];
		gotoXY(b, 6); cout << symbols[1][1];
		gotoXY(c, 6); cout << symbols[1][2];

		gotoXY(a, 8); cout << symbols[2][0];
		gotoXY(b, 8); cout << symbols[2][1];
		gotoXY(c, 8); cout << symbols[2][2];
	}

	int win()
	{
		if (symbols[0][0] == symbols[0][1] and symbols[0][1] == symbols[0][2])
		{
			if (symbols[0][0] == '0') return 2;
			else if (symbols[0][0] == 'X') return 1;
		}
		else if (symbols[1][0] == symbols[1][1] and symbols[1][0] == symbols[1][2]) {
			if (symbols[1][0] == '0') return 2;
			else if (symbols[1][0] == 'X') return 1;
		}
		else if (symbols[2][0] == symbols[2][1] and symbols[2][1] == symbols[2][2]) {
			if (symbols[2][0] == '0') return 2;
			else if (symbols[2][0] == 'X') return 1;
		}

		else if (symbols[0][0] == symbols[1][0] and symbols[1][0] == symbols[2][0]) {
			if (symbols[0][0] == '0') return 2;
			else if (symbols[0][0] == 'X') return 1;
		}
		else if (symbols[0][1] == symbols[1][1] and symbols[1][1] == symbols[2][1]) {
			if (symbols[0][1] == '0') return 2;
			else if (symbols[0][1] == 'X') return 1;
		}
		else if (symbols[0][2] == symbols[1][2] and symbols[0][2] == symbols[2][2]) {
			if (symbols[0][2] == '0') return 2;
			else if (symbols[0][2] == 'X') return 1;
		}
		else if (symbols[0][0] == symbols[1][1] and symbols[1][1] == symbols[2][2]) {
			if (symbols[0][0] == '0') return 2;
			else if (symbols[0][0] == 'X') return 1;
		}
		else if (symbols[0][2] == symbols[1][1] and symbols[1][1] == symbols[2][0]) {
			if (symbols[0][2] == '0') return 2;
			else if (symbols[0][2] == 'X') return 1;
		}
		return 0;
	}

	void input(char in)
	{
		int x = 22;
		int y = 4;
		system("cls");
		ShowBoard(20);
		KeyValue key;
		gotoXY(x, y);
		cout << in;
		for (int i = 0; i < 15; i++)
		{
			gotoXY(50, i);
			cout << "|";
		}
		gotoXY(20, 1);
		cout << "Поле для выбора шага";
		gotoXY(60, 1);
		cout << "Игровое поле";
		while (true)
		{
			ShowBoard(60);
			ShowValues(62, 67, 72);
			int(key) = (int)_getch();
			if (key == LEFT)
			{
				clear_pos(x, y);
				if (x == 22 and y > 4)
				{
					x = 32;
					y -= 2;
				}
				else x -= 5;
				if (current_y == 0 and current_x > 0) {
					current_y = 2;
					current_x--;
				}
				else if (current_y > 0) current_y--;
			}
			if (key == UP and y != 4)
			{
				clear_pos(x, y);
				y -= 2;
				current_x--;
			}
			if (key == DOWN and y != 8)
			{
				clear_pos(x, y);
				y += 2;
				current_x++;
			}
			if (key == RIGHT)
			{
				clear_pos(x, y);
				if (x == 32 and y < 8)
				{
					x = 22;
					y += 2;
				}
				else x += 5;
				if (current_y == 2 and current_x < 2) {
					current_y = 0;
					current_x++;
				}
				else if (current_y != 2) current_y++;
			}
			if (key == ENTER)
			{
				if (symbols[current_x][current_y] == ' ') {
					symbols[current_x][current_y] = in;
					resetXY();
					break;
				}
				else
					continue;
			}
			if (x < 22) x = 22;
			if (x > 32) x = 32;
			gotoXY(x, y);
			cout << in;
		}
	}
};
