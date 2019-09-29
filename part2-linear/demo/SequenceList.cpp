#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;

struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last;
};

List MakeEmpty()
{
    List PtrL;
    PtrL = new LNode;
    PtrL->Last = -1;
    return PtrL;
}

int Find(ElementType X, List PtrL)
{
    int i = 0;
    while (i <= PtrL->Last && PtrL->Data[i] != X)
        i++;
    if (i > PtrL->Last)
        return -1;
    else
        return i;
}

void Insert(ElementType X, int i, List PtrL)
{
    int j;
    if (PtrL->Last == MAXSIZE - 1)
    {
        cout << "表满" << endl;
        return;
    }
    if (i < 1 || i > PtrL->Last + 2)
    {
        cout << "插入位置不合法";
        return;
    }
    for (j = PtrL->Last; j >= i - 1; j--)
        PtrL->Data[j + 1] = PtrL->Data[j];
    PtrL->Data[i - 1] = X;
    PtrL->Last++;
    return;
}

void Delete(int i, List PtrL)
{
    int j;
    if (i < 1 || i > PtrL->Last + 1)
    {
        cout << "不存在第" << i << "个元素" << endl;
        return;
    }
    for (j = i; j <= PtrL->Last; j++)
        PtrL->Data[j - 1] = PtrL->Data[j];
    PtrL->Last--;
    return;
}

int main(int argc, char const *argv[])
{
    List myList = MakeEmpty();
    for (int i = 1; i <= 10; i++)
    {
        Insert(i, i, myList);
    }
    //Insert(-1, 1, myList);
    Delete(3, myList);
    return 0;
}
