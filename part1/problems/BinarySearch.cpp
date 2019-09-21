#include <iostream>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

Position BinarySearch(List L, ElementType X);

int main()
{
    List L = new LNode;
    ElementType X;
    Position P;

    L->Data[1] = 12;
    L->Data[2] = 31;
    L->Data[3] = 55;
    L->Data[4] = 89;
    L->Data[5] = 101;
    L->Last = 5;

    X = 31;
    P = BinarySearch(L, X);
    std::cout << P << std::endl;
    return 0;
}

Position BinarySearch(List L, ElementType X)
{
    Position low = 0, high = L->Last;
    while (low <= high)
    {
        Position middle = (low + high) / 2;
        if (X == L->Data[middle])
        {
            return middle;
        }
        else if (X > L->Data[middle])
        {
            low = middle + 1;
        }
        else if (X < L->Data[middle])
        {
            high = middle - 1;
        }
    }
    return NotFound;
}
