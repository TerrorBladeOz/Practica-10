#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include <string>
using namespace std;

void a1()
{
    int a, b, sum = 0, max, min; double avr;
    int** dig;
    cout << "Введите кол-во столбцов: "; cin >>a;
    cout << "Введите кол-во строк: "; cin >> b;

    dig = new int* [a];
    for (int i = 0; i < a; i++)
        dig[i] = new int[b];

    for (int i = 0; i < a; i++) // ввод 
        for (int j = 0; j < b; j++)
        {
            dig[i][j] = rand() % 100;
            sum = sum + dig[i][j];
        }

    avr = sum / (a * b);

    for (int i = 0; i < a; i++) 
    {
        cout << "|| ";
        for (int j = 0; j < b; j++)
        {
            cout << dig[i][j] << ", ";
        }
        cout << "||\n";
    }



    max = dig[0][0];
    min = dig[0][0];
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (max < dig[i][j]) max = dig[i][j];
            if (min > dig[i][j]) min = dig[i][j];
        }
    }

    cout << "Сумма всех чисел = "<<sum<<endl;
    cout << "Среднее арифметическое = " << avr << endl;
    cout << "Максимальный элемент = " << max << endl;
    cout << "Минимальный элемент = " << min << endl;


}

void a2()
{
    srand(time(0));
    int a, b; int Sum = 0, Sum_total = 0;
    int** dig;
    cout << "Введите кол-во столбцов: "; cin >> a;
    cout << "Введите кол-во строк: "; cin >> b;

    dig = new int* [a];

    for (int i = 0; i < a; i++)
    {
        dig[i] = new int[b];
    }
       
    for (int i = 0; i < a; i++) 
    {
        for (int j = 0; j < b; j++) 
        {
            dig[i][j] = rand() % 100;
            cout << dig[i][j] << "\t";
            Sum += dig[i][j];
        }
        cout << "|\t" << Sum << "\n\n";
        Sum = 0;
    }
    string s(a*6+(a*2)+11, '-');
    cout <<s <<"\n\n";
    for (int j = 0; j < a; j++) 
    {
        for (int i = 0; i < b; i++) 
        {
            Sum += dig[i][j];
        }
        Sum_total += Sum;
        cout << Sum << "\t";
        Sum = 0;
        
    }
    cout << "|\t" << Sum_total << "\n\n";
}

void a3()
{
    const int h = 5, g = 10;
    int dig[h][g],dig1[h][h];
    for (int i = 0; i < h; i++) 
        for (int j = 0; j < g; j++)
        {
            dig[i][j] = rand() % 50;
        }
    cout << "Первый массив >>> \n";
    for (int i = 0; i < h; i++)
    {
        cout << "| ";
        for (int j = 0; j < g; j++)
        {
            cout << dig[i][j] << ", ";
        }
        cout << " |\n";
    }
    cout << "Второй массив >>> \n";
    for (int i = 0; i < h; i++)
    {
        cout << "| ";
        for (int j = 0; j < h; j++)
        {

            dig1[i][j] = dig[i][j * 2] + dig[i][j * 2 + 1];

            cout << dig1[i][j] << ", ";
        }
        cout << " |\n";
    }
}

void main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "rus");
    int f;
    do {
        cout << "\n\nПервая 1 - 3   >>> "; cin >> f;
        switch (f)
        {
        case 1:
            a1();
            break;
        case 2:
            a2();
            break;
        case 3:
            a3();
            break;
      
        }
    } while (f != 0);
}

