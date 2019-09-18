#include <iostream>

using namespace std;

void rotateOnce(int *arr, int N);
void printArrary(int *arr, int N);

int main()
{
    int N, M;

    while (cin >> N >> M)
    {
        int *array = new int[N];
        for (size_t i = 0; i < N; i++)
        {
            cin >> array[i];
        }
        for (size_t i = M % N; i > 0; i--)
        {
            rotateOnce(array, N);
        }
        printArrary(array, N);
    }
    return 0;
}

void rotateOnce(int *arr, int N)
{
    int last = arr[N - 1];
    for (size_t i = N - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
}

void printArrary(int *arr, int N)
{
    for (size_t i = 0; i < N - 1; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << arr[N - 1] << endl;
}