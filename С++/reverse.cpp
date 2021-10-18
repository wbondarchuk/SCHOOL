#include <iostream>
using namespace std;
 
int main()
{
  setlocale(LC_ALL, "rus");
  int number = 0;
  cout << "Введите число" << endl;
  cin >> number;
  cout << "Дано целое число: " << number << endl;
  cout << "Число  наизнанку: "; 
  // остаток от деления четырехзначного числа на 10
  cout << number % 10; 
  // далее делим number на 10 и записываем в переменную 
  // так как тип переменной int, дробная часть отбросится 
  number /= 10; 
  // показываем остаток от деления на 10 на экран
  cout << number % 10; 
  number /= 10;
  cout << number % 10;
  number /= 10;
  cout << number % 10;
  number /= 10;
 
  cout << endl << endl;
 
  return 0;
}
