#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
bool isPrime(int num);

int main()
{
    int N;
    vector<int> primes;
    primes.push_back(2);
    for (size_t i = 3; i < 100000; i++)
    {
        if (isPrime(i))
        {
            primes.push_back(i);
        }
    }

    while (cin >> N)
    {
        int count = 0;
        for (auto i = primes.begin(); i != primes.end(); ++i)
        {
            // cout << i[0] << ' ' << i[1] << endl;
            if (i[1] <= N)
            {
                if (i[1] - i[0] == 2)
                {
                    count += 1;
                }
            }
            else
            {
                break;
            }
        }
        cout << count << endl;
    }
    return 0;
}

bool isPrime(int num)
{
    for (size_t i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}