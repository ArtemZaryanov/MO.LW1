// MO.LW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <vector>
double Function(const double x);
void Sven(double& a, double& b, const double t);
double Dichotomy(const double a, const double b, const double e);
double GoldSection(const double a, const double b, const double e);
double FibonacciMethod(const double a, const double b, const double e);
std::vector<double> FibonacciNumberList(const int N);
int main()
{
    std::cout << "Hello World!\n";
    double a = 0.5;
    double b = 10.5;
    const double t = (b - a) / 100;
    
    std::cout << "Sven..." << std::endl;
    Sven(a, b, t);
    std::cout << "Search interval : " << a << ", " << b << std::endl;
    std::cout << "Dichotomy" << std::endl;
    const double e = 0.0001;
    double x = Dichotomy(a, b, e);
    std::cout << "Dichotomy::Minimum x=" << x << " f(x)=" << Function(x) << std::endl;
    std::cout << "GoldSection" << std::endl;;
    x = GoldSection(a, b, e);
    std::cout << "GoldSection::Minimum x=" << x << " f(x)=" << Function(x) << std::endl;
    std::cout << "FibonacciMethod" << std::endl;;
    x = FibonacciMethod(a, b, e);
    std::cout << "FibonacciMethod::Minimum x=" << x << " f(x)=" << Function(x) << std::endl;
    //TODO Проверить функию. По идее она должна быть быстрее в смысле числа итераций

}

double Function(const double x)
{
    if (x < 1)
    {
        return 1 / (1 + x * x);
    }
    else
    {
        return (2 * x * x - 5 * x - 15) / (x * x * x * x);
    }
}
void Sven(double& a, double& b, const double t)
{
    double x0 = (a + b) / 2;
    double f0 = Function(x0 - t);
    double f = Function(x0);
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
        double buf = 0;
        int k = 1;
        std::cout << "delta=" << delta << std::endl;
        std::cout << "Search..." << std::endl;
        while (true)
        {
            buf = x0 +2*k * delta;
            x0 = x1;
            x1 = buf;
            if (Function(x1) < Function(x0))
            {
                //Могут быть ошибки точности ы
                if (delta>0)
                {
                    a = x0;
                    //std::cout << "+" << (delta - t)<< std::endl;
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
                if ((delta > 0))
                {
                    b = x1;
                }
                else
                {
                    a = x1;
                }
                return;
            }
            k = k + 1;


        }
    }
    else
    {
        //функция не унимодальна
    }
}
double Dichotomy(const double a , const double b, const double e)
{
    double iter = 1;
    double ak = a;
    double bk = b;
    double ck = (a + b) / 2;
    do
    {
        //std::cout << "Search interval : " << ak << ", " << bk << std::endl;
        double fck = Function(ck);
        double yk = (ak + ck) / 2;
        double fy = Function(yk);
        double zk = 0;
        double fzk = 0;
        if (fy <= fck)
        {
            ak = ak;
            bk = ck;
            ck = yk;
        }
        if (fy > fck)
        {
            zk = (bk + ck) / 2;
            fzk = Function(zk);
            if (fck <= fzk)
            {
                ak = yk;
                bk = zk;
                ck = ck;
            }
            else
            {
                ak = ck;
                bk = bk;
                ck = zk;
            }
        }
        
        iter++;
    } while (abs(bk - ak)>=e);
    std::cout << "iter=" << iter << std::endl;
    return (ak + bk) / 2;
}
double GoldSection(const double a, const double b, const double e)
{
    std::function<double(double, double)> ykgs = [](double a, double b)
    {
        return a + ((3 - sqrt(5)) / 2) * (b - a);
    };
    std::function<double(double, double)> zkgs = [](double a, double b)
    {
        return a + ((sqrt(5) -1) / 2) * (b - a);
    };
    double iter = 1;
    double ak = a;
    double bk = b;
    //double ck = (a + b) / 2;
    do
    {
        //std::cout << "Search interval : " << ak << ", " << bk << std::endl;
        //double fck = Function(ck);
        double yk = ykgs(ak,bk);
        double fyk = Function(yk);
        double zk = zkgs(ak, bk);
        double fzk = Function(zk);
        if (fyk <= fzk)
        {
            ak = ak;
            bk = zk;
            yk = ykgs(ak, bk);
            zk = yk;
        }
        else
        {
            ak = yk;
            bk = bk;
            yk = zk;
            zk = zkgs(ak, bk);
        }

        iter++;
    } while (abs(bk - ak) >= e);
    std::cout << "iter=" << iter << std::endl;
    return (ak + bk) / 2;

}
double FibonacciMethod(const double a, const double b, const double e)
{
    double iter = 1;
    double ak = a;
    double bk = b;
    //Вычисления количества чисел Фибоначи
    std::vector<double> F{ 0,1, 1};
    int N = 0;
    while (F.back() <= (b - a) / e)
    {
        F.push_back(F[N + 2] + F[N + 1]);
        N++;
        iter++;
    }
    int k = 0;
    double yk = ak + (F[N] / F[N + 2]) * (bk - ak);
    double fyk = Function(yk);
    double zk = ak + (F[N + 1] / F[N + 2]) * (bk - ak);
    double fzk = Function(zk);
    while (k < N - 1)
    {
        if (fyk <= fzk)
        {
            ak = ak;
            bk = zk;
            yk = ak + (F[N - k] / F[N - k + 2]) * (bk - ak);
            zk = yk;
        }
        else
        {
            ak = yk;
            bk = bk;
            yk = zk;
            zk = ak + (F[N - k + 1] / F[N - k + 2]) * (bk - ak);
        }

        k++;
        iter++;
    }
    std::cout << "iter=" << iter<< std::endl;
    return (ak + bk) / 2;
      
}

std::vector<double> FibonacciNumberList(const int N)
{
    std::vector<double> F{ 0,1, 0 };
    for (size_t k = 2; k <= N + 2; k++)
    {
        F[k] = F[k - 1] + F[k - 2];
        F.push_back(F[k]);
    }
    return F;
}
