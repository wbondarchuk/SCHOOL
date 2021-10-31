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

	cout << "����� * � Enter, ����� ������� ������: ";
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
	cout << "����� �� ������� " << result << " �����";
	return result;
}






void gameresult(int computerScore, int playerScore, int number)
{
	cout << "\n-------------------\n";
	cout << "���������: " << computerScore << "  |  �����:" << playerScore << endl;
	cout << "����� " << number + 1 << "-�� ������ ";
	if (computerScore > playerScore)
	{
		cout << " ���������� ���������!\n";
	}
	else if (computerScore < playerScore)
		cout << " ���������� �����!\n";
	else cout << " �����!!!\n";
	cout << "---------------------\n\n";
}





int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	cout << "������! ���� ���� ������: ����� ������� ������ � �������� ���������� ���������� �����.\n";
	cout << "� ���� ���� ��� ����, ����� �������� ���������! �������!" << endl << endl;

	int scoreOfp = 0;
	int scoreOfc = 0;
	int who = rand() % 2;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; j++)
		{
			if (who)
			{
				cout << "\n����� �����. ";
				scoreOfp += gameProgress();
			}
			else
			{
				cout << "\n����� ���������. ";
				scoreOfc += gameProgress();
			}
			who = !who;
		}
		gameresult(scoreOfc, scoreOfp, i);
	}

	if (scoreOfc > scoreOfp)
	{
		cout << "\n\n��������� �������!\n";
		cout << "������ ������� � ��������� ���.\a\a\a\a\a\n\n";
	}
	else if (scoreOfp > scoreOfc)
	{
		cout << "\n\n�� ����������!";
		cout << "�����������!\a\a\a\a\a\n\n";
	}
	else
	{
		cout << "\n\n� ���� ���� �����!\a\a\a\a\a\n\n";
	}
	system("pause");
	return 0;
}



