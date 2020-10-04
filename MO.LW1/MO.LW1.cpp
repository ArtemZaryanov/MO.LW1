// MO.LW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <math.h>
#include <functional>

double Function(const double x)
{
    return (x - 2) * (x - 2);
}
void Sven(double& a, double& b, const double t)
{
    double x0 = (a + b) / 2;
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

        double delta = 0;
        double x1 = 0;
        if ((f <= f0) && (f >= f1))
        {
            a = x0;
            x1 = x0 + t;
            delta = t;
        }
        if ((f >= f0) && (f <= f1))
        {
            x1 = x0 - t;
            b = x0;
            delta = -t;

        }
        //Собственно сам поиск
        int buf = 0;
        int k = 1;
        while (true)
        {
            buf = x0 + pow(2, k) * delta;
            x0 = x1;
            x1 = buf;
            if (Function(x1) < Function(x0))
            {
                //Могут быть ошибки точности ы
                if (delta == t)
                {
                    a = x0;
                }
                else
                {
                    b = x0;
                }

            }
            //условие останова
            else
            {
                //Могут быть ошибки точности ы
                if (delta == t)
                {
                    b = x1;
                }
                else
                {
                    a = x1;
                }
            }
            k = k + 1;
            

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
int main()
{
    std::cout << "Hello World!\n";
    double a = 0;
    double b = 10;
    const double t = (b - a) / 100;
    Sven(a, b, t);
    std::cout << "Sven..." << std::endl;
    std::cout << "Search interval : " << a << ", " << b << std::endl;
    

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
