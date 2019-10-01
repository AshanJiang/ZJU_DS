#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct LinkedNode *LinkedList;
struct LinkedNode
{
    int address;
    int data;
    int nextAddress;
    LinkedList next;
};
struct find_address
{
    int address;
    find_address(int address) : address(address) {}
    bool operator()(const LinkedList &n) const
    {
        return n->address == address;
    }
};
int formatAddress(string address);
void printList(LinkedList list);
int main()
{
    //1.读数据
    int start, total, reverse, data;
    string tmp;
    cin >> tmp;
    start = formatAddress(tmp);
    cin >> total;
    cin >> reverse;
    vector<LinkedList> arr;
    for (int i = 0; i < total; i++)
    {
        LinkedList node = new LinkedNode;
        cin >> tmp;
        node->address = formatAddress(tmp);
        cin >> data;
        node->data = data;
        cin >> tmp;
        node->nextAddress = formatAddress(tmp);
        node->next = NULL;
        arr.push_back(node);
    }
    //2.构造链表
    vector<LinkedList>::iterator it;
    it = find_if(arr.begin(), arr.end(), find_address(start));
    LinkedList list = (*it); //结果链表头
    LinkedList cur = list;   //表尾指针
    while (true)
    {
        int nextAddress = cur->nextAddress;
        if (nextAddress == -1)
            break;
        it = find_if(arr.begin(), arr.end(), find_address(nextAddress));
        cur->next = *it;
        cur = cur->next;
    }
    //3.反转链表
    if (reverse > 1)
    {
        LinkedList pre, next, stop;
        int tmpReverse = reverse;
        stop = list;
        while (tmpReverse--)
        {
            stop = stop->next;
        }
        pre = NULL;
        cur = list;
        next = cur->next;
        while (reverse--)
        {
            if (pre)
                cur->nextAddress = pre->address;
            cur->next = pre;
            pre = cur;
            cur = next;
            if (cur->next)
                next = cur->next;
        }
        list->nextAddress = stop->address;
        list->next = stop;
        list = pre;
    }
    printList(list);
    return 0;
}

int formatAddress(string address)
{
    return stoi(address.erase(0, min(address.find_first_not_of('0'), address.size() - 1)));
}

void printList(LinkedList list)
{
    while (list)
    {
        cout << setw(5) << setfill('0') << list->address;
        cout << ' ' << list->data << ' ';
        if (list->nextAddress == -1)
            cout << list->nextAddress;
        else
            cout << setw(5) << setfill('0') << list->nextAddress;
        cout << endl;
        list = list->next;
    }
}