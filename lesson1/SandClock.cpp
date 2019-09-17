#include <iostream>

using namespace std;

int main()
{
    int N;
    char c;
    while (cin >> N >> c)
    {
        if (N < 7)
        {
            cout << c << endl;
            cout << N - 1 << endl;
        }
        else
        {
            //i代表最高行有多少个符号
            int i = 1, j, k = 0;
            while (((3 + i + 2) * (i + 2 - 1)) / 2 <= N - 1)
            {
                i += 2;
            }
            for (j = i; j >= 1; j -= 2)
            {
                cout << string(k, ' ') << string(j, c) << endl;
                k += 1;
            }
            k--;
            for (j = 3; j <= i; j += 2)
            {
                k-=1;
                cout << string(k, ' ') << string(j, c) << endl;
            }
            cout << N - (1 + ((3 + i) * (i - 1)) / 2) << endl;
        }
    }
    return 0;
}