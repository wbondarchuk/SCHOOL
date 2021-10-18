#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    double a, b, c;
    char op;
    cout << "Первое число: ";
    cin >> a;
    cout << "Второе число: ";
    cin >> b;
    cout << "Действие: ";
    cin >> op;
    switch (op)
    {
    case '+':   
        c = a + b; 
        break;

    case '-':   
        c = a - b;
        break;

    case '*':
        c = a * b;
        break;

    case '/':   
        c = a / b;
        break;

    case '%':   
        c = a * b / 100; 
        break;

    default:    
        cout << "Не верное значение.";
    }
    cout << "Ответ: " << c << endl;
    system("PAUSE");
    return 0;
}
