#include <iostream>

using namespace std;

int main()
{
  int N;
  int maxSum = 0, thisSum = 0;

  while (cin >> N)
  {
    int a[N];
    for (int i = 0; i < N; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
      thisSum += a[i];
      if (thisSum > maxSum)
      {
        maxSum = thisSum;
      }
      else if (thisSum < 0)
      {
        thisSum = 0;
      }
    }
    cout << maxSum << endl;
  }

  return 0;
}