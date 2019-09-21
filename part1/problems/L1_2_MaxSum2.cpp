#include <iostream>
using namespace std;

int main()
{
    int N = 10;
    int maxSum, thisSum, min, max, currentStart;
    bool isStart = true;
    while (cin >> N)
    {
        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }
        maxSum = thisSum = 0;
        min = a[0];
        max = a[N - 1];
        for (int i = 0; i < N; i++)
        {
            if (isStart)
            {
                currentStart = a[i];
                isStart = false;
            }

            thisSum += a[i];
            if (thisSum > maxSum)
            {
                maxSum = thisSum;
                min = currentStart;
                max = a[i];
            }
            else if (thisSum < 0)
            {
                thisSum = 0;
                isStart = true;
            } else if(thisSum == 0 && maxSum==0){
                //序列只有负数和0
                min = max = 0;
            }
        }
        cout << maxSum << ' ' << min << ' ' << max << endl;
    }

    return 0;
}