#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;


void draw(int res)
{
	switch (res)
	{
	case 1:
		cout << "       \n";
		cout << "       \n";
		cout << "   *   \n";
		cout << "       \n";
		cout << "       \n";
		break;
	case 2:
		cout << "       \n";
		cout << "  *    \n";
		cout << "       \n";
		cout << "     * \n";
		cout << "       \n";
		break;
	case 3:
		cout << "       \n";
		cout << "  *    \n";
		cout << "    *  \n";
		cout << "     * \n";
		cout << "       \n";
		break;
	case 4:
		cout << "       \n";
		cout << "  *  * \n";
		cout << "       \n";
		cout << "  *  * \n";
		cout << "       \n";
		break;
	case 5:
		cout << "       \n";
		cout << " *   * \n";
		cout << "   *   \n";
		cout << " *   * \n";
		cout << "       \n";
		break;
	case 6:
		cout << "       \n";
		cout << " *   * \n";
		cout << " *   * \n";
		cout << " *   * \n";
		cout << "       \n";
		break;
	}
}




int gameProgress()
{
	char a = 0;
	int value = 0;
	int result = 0;

	cout << "Нажми * и Enter, чтобы бросить кубики: ";
	do
	{
		cin.sync();
		cin >> a;
	} while (a != '*');

	for (int i = 0; i < 2; i++)
	{
		value = 1 + rand() % 6;
		draw(value);
		result += value;
		cout << endl;
	}
	cout << "Всего на кубиках " << result << " очков";
	return result;
}






void gameresult(int computerScore, int playerScore, int number)
{
	cout << "\n-------------------\n";
	cout << "Компьютер: " << computerScore << "  |  Игрок:" << playerScore << endl;
	cout << "После " << number + 1 << "-го броска ";
	if (computerScore > playerScore)
	{
		cout << " выигрывает компьютер!\n";
	}
	else if (computerScore < playerScore)
		cout << " выигрывает Игрок!\n";
	else cout << " ничья!!!\n";
	cout << "---------------------\n\n";
}





int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "Привет! Суть игры проста: нужно бросать кубики и выбирать наибольшее количество очков.\n";
	cout << "У тебя есть три хода, чтобы обыграть компьютер! Поехали!" << endl << endl;

	int scoreOfp = 0;
	int scoreOfc = 0;
	int who = rand() % 2;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			if (who)
			{
				cout << "\nХодит Игрок. ";
				scoreOfp += gameProgress();
			}
			else
			{
				cout << "\nХодит компьютер. ";
				scoreOfc += gameProgress();
			}
			who = !who;
		}
		gameresult(scoreOfc, scoreOfp, i);
	}

	if (scoreOfc > scoreOfp)
	{
		cout << "\n\nКомпьютер победил!\n";
		cout << "Желаем успехов в следующий раз.\a\a\a\a\a\n\n";
	}
	else if (scoreOfp > scoreOfc)
	{
		cout << "\n\nВы победитель!";
		cout << "Поздравляем!\a\a\a\a\a\n\n";
	}
	else
	{
		cout << "\n\nВ этой игре ничья!\a\a\a\a\a\n\n";
	}
	system("pause");
	return 0;
}



