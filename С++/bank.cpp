#include <iostream>
using namespace std;
 
int main()
{
  setlocale(LC_ALL, "rus");
 
  float sumDeposit = 0; // сумма депозита
  int amountMonth = 0; // количество месяцев
  float profit = 0; // прибыль
  float annualRate = 5; // пять процентов годовых
  int daysInYear = 365;
  int daysInMonth = 30;
 
  cout << "Введите сумму депозита в долларах: ";
  cin >> sumDeposit;
  cout << "Введите количество месяцев: ";
  cin >> amountMonth;
 
  cout << "\nРасчет\n";
  cout << "=======================================\n";
  cout << "Проценты в месяц: ";
  // проводим расчет по формуле и записываем в переменную profit
  profit = sumDeposit * (annualRate / 100)  / daysInYear * daysInMonth;
 
  cout << sumDeposit << " * " << annualRate << "%  / " << daysInYear << " * " << daysInMonth << " = " << profit << " $" << endl;
 
  cout << "Проценты за весь срок: ";
  // умножаем % за 1 месяц на весь срок депозита и записываем в profit
  profit *= amountMonth;
  cout << profit << " $"  << endl;
 
  cout << "Общая сумма выплаты в конце срока: " << sumDeposit + profit  << " $";
  cout << endl << endl;
 
  return 0;
}
