#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    int carried = 0, a, b, tmp;
    ListNode *res, *p1, *p2, *cur;
    res = new ListNode(-1);
    cur = res;
    p1 = l1;
    p2 = l2;
    while (p1 || p2)
    {
        if (p1)
            a = p1->val;
        else
            a = 0;
        if (p2)
            b = p2->val;
        else
            b = 0;
        tmp = a + b + carried;
        if (tmp >= 10)
        {
            cur->val = tmp % 10;
            carried = 1;
        }
        else
        {
            cur->val = tmp;
            carried = 0;
        }
        if (p1)
            p1 = p1->next;
        if (p2)
            p2 = p2->next;
        if (p1 || p2)
        {
            ListNode *newNode = new ListNode(-1);
            cur->next = newNode;
            cur = newNode;
        }
        else if (carried == 1) //处理进位后多出一位
        {
            ListNode *newNode = new ListNode(1);
            cur->next = newNode;
        }
    }
    return res;
}

int main()
{
    ListNode *l1 = new ListNode(1);
    ListNode *l1_2 = new ListNode(8);
    l1->next = l1_2;
    //ListNode *l1_3 = new ListNode(3);
    //l1_2->next = l1_3;

    ListNode *l2 = new ListNode(0);
    //ListNode *l2_2 = new ListNode(6);
    //l2->next = l2_2;
    //ListNode *l2_3 = new ListNode(4);
    //l2_2->next = l2_3;

    ListNode *res = addTwoNumbers(l1, l2);

    return 0;
}
