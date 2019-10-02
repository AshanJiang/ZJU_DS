#include<iostream>  
#include<stdio.h>  
#include<algorithm>
#include <iomanip>

using namespace std;

#define MAXSIZE 100010

struct node  
{
	int data;
	int next;
};

int list[MAXSIZE];
struct node node[MAXSIZE];
int main()
{
	int start, n, k, i, j, p;
	cin >> start >> n >> k;
	int address, data, next;
	for (i = 0; i < n; i++)
	{
		cin >> address >> data >> next;
		node[address].data = data;
		node[address].next = next;
	}

	j = 0;
	p = start;
	while (p != -1)
	{
		//按照节点地址顺序排列的数组
		list[j++] = p;
		p = node[p].next;
	}
	i = 0;
	while (i + k <= j)   //每k个节点做一次翻转  
	{
		reverse(&list[i], &list[i + k]);
		i = i + k;
	}
	for (i = 0; i < j - 1; i++) { //注意：这里不能用给定的n，因为有可能有节点不在链表上
		cout << setw(5) << setfill('0') << list[i];
		cout << ' ' << node[list[i]].data << ' '; 
		cout << setw(5) << setfill('0') << list[i + 1] << endl;
	}
	cout << setw(5) << setfill('0') << list[i];
	cout << ' ' << node[list[i]].data << ' ';
	cout << -1 << endl;
	return 0;
}
