#include <iostream>

using namespace std;

void printN1(int N);
void printN2(int N);

int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    printN2(N);
}

void printN1(int N)
{
    for (int i = 1; i <= N; i++)
    {
        cout << i << endl;
    }
    return;
}

void printN2(int N)
{
    if (N)
    {
        printN2(N - 1);
        cout << N << endl;
    }
    return;
}