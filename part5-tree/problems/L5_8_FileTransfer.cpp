#include <iostream>
using namespace std;

constexpr auto MaxSize = 10010;
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MaxSize];
SetName Find(SetType S, ElementType X);
void Union(SetType S, SetName Root1, SetName Root2);
void Union_scale(SetType S, SetName Root1, SetName Root2);
void Initialization(SetType &S, ElementType n);
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S, ElementType n);

int main()
{
	SetType S;
	int n;
	char in;
	cin >> n;
	Initialization(S, n);
	do {
		cin >> in;
		switch (in)
		{
		case 'I': Input_connection(S); break;
		case 'C': Check_connection(S); break;
		case 'S': Check_network(S, n); break;
		}
	} while (in != 'S');
	return 0;
}

SetName Find(SetType S, ElementType X) 
{
	//数组下标是数据，数组内容是父节点
	for (; S[X] >= 0; X = S[X]);
	return X;
}

void Union(SetType S, SetName Root1, SetName Root2)
{
	//按高度归并
	//假设Root2和Root1是不同集合根节点
	if (S[Root2] < S[Root1])
		S[Root1] = Root2;
	else{
		if (S[Root2] == S[Root1]) S[Root1]--;
		S[Root2] = Root1; //把Root2连接向Root1
	}
}

void Union_scale(SetType S, SetName Root1, SetName Root2)
{
	//按规模归并
	if (S[Root2] < S[Root1]) {
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else {
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

void Initialization(SetType & S, ElementType n)
{
	int i;
	for (i = 0; i < n; i++)
		S[i] = -1;
}

void Input_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	//判断是否互连，若不，连接起来
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 != Root2) {
		Union_scale(S, Root1, Root2);
	}
}

void Check_connection(SetType S)
{
	ElementType u, v;
	SetName Root1, Root2;
	cin >> u >> v;
	Root1 = Find(S, u - 1);
	Root2 = Find(S, v - 1);
	if (Root1 == Root2)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

void Check_network(SetType S, ElementType n)
{
	int i, counter = 0;
	for (i = 0; i < n; i++)
		if (S[i] < 0) counter++;
	if (counter == 1)
		cout << "The network is connected." << endl;
	else
		cout << "There are " << counter << " components." << endl;
}
