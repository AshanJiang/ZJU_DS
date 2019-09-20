#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

clock_t start, stop;
double duration;
#define MAXN 10
#define MAXK 1e7 //最大重复调用次数

//n:项数,a:系数,x:就是x
double function1(int n, double a[], double x)
{
    int i;
    double p = a[0];
    for (i = 1; i <= n; i++)
    {
        p += a[i] * pow(x, i);
    }
    return p;
}

double function2(int n, double a[], double x)
{
    int i;
    double p = a[n];
    for (i = n; i > 0; i--)
    {
        p = a[i - 1] + x * p;
    }
    return p;
}

int main()
{
    int i;
    double a[MAXN];
    for (i = 0; i < MAXN; i++)
        a[i] = (double)i;

    start = clock();
    for (i = 0; i < MAXK; i++)
        function1(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)stop - start) / CLOCKS_PER_SEC / MAXK;
    cout << fixed << "ticks1: " << (double)(stop - start) << ' ';
    cout << scientific << "duration1: " << duration << "seconds." << endl;

    start = clock();
    for (i = 0; i < MAXK; i++)
        function2(MAXN - 1, a, 1.1);
    stop = clock();
    duration = ((double)stop - start) / CLOCKS_PER_SEC / MAXK;
    cout << fixed << "ticks2: " << (double)(stop - start) << ' ';
    cout << scientific << "duration2: " << duration << "seconds." << endl;

    return 0;
}