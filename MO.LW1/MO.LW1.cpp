// MO.LW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <functional>

void Sven(double& a, double& b, const double t)
{
    double x0 = (a + b) / 2;
    double x1 = 0'
    double f0 = Function(x0 - t);
    double f = Function(x0 - t);
    double f1 = Function(x0 + t);
    if (!((f >= f0) && (f >= f1)))
    {
         //Функция унимодальна!
        if ((f <= f0) && (f <= f1))
        {
            a = x0 - t;
            b = x0 + t;
            return;
        }
        //Собственно сам поиск
        if ((f <= f0) && (f >= f1))
        {
            a = x0;
            x1 = x0 + t;
        }
        if ((f >=f0) && (f <=f1))
        {
            x1 = x0 - t;
            b = x0;
        }
    }
    else
    {
        //функция не унимодальна 
    }
}
void Dichotomy()
{
    ;
}
void GoldSection()
{
    ;
}
void Fibonacci()
{
    ;
}
double Function(const double x)
{
    return x * x;
}
int main()
{
    const double a = 0;
    const double b = 10;
    const double t = (b - a) / 100;
    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
