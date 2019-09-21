#include <iostream>
using namespace std;
/*
在线处理最大子列和
*/
int maxSum(int A[], int N)
{
    int maxSum, thisSum;
    maxSum = thisSum = 0;
    for (int i = 0; i < N; i++)
    {
        thisSum += A[i];
        if (thisSum > maxSum)
        {
            maxSum = thisSum; //发现更大值则更新当前结果
        }
        else if (thisSum < 0)
        { //发现当前子列和为负数，则抛弃
            thisSum = 0;
        }
    }
    return maxSum;
}

int main()
{
    int a[] = {-1, 3, -2, 4, -6, 1, 6, -1};
    int res = maxSum(a, 8);
    cout << "res=" << res << endl;
    return 0;
}