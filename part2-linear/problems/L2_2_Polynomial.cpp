#include <iostream>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode
{
	int coef;
	int expon;
	Polynomial link;
};

Polynomial ReadPoly();
void PrintPoly(Polynomial P);
void Attach(int c, int e, Polynomial &pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
Polynomial Mult(Polynomial P1, Polynomial P2);
int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	PP = Mult(P1, P2);
	PrintPoly(PP);
	PS = Add(P1, P2);
	PrintPoly(PS);
	return 0;
}

Polynomial ReadPoly()
{
	Polynomial P, Rear, t;
	int c, e, N;
	cin >> N;
	P = new PolyNode;
	P->link = NULL;
	Rear = P;
	while (N--)
	{
		cin >> c >> e;
		Attach(c, e, Rear);
	}
	t = P;
	P = P->link;
	delete t;
	return P;
}

void PrintPoly(Polynomial P)
{
	int flag = 0; //控制空格，保证最后没有空格
	if (!P)
		cout << "0 0";
	while (P)
	{
		if (!flag)
			flag = 1;
		else
			cout << " ";
		cout << P->coef << " " << P->expon;
		P = P->link;
	}
	cout << endl;
}

void Attach(int c, int e, Polynomial &pRear)
{
	Polynomial P;

	P = new PolyNode;
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	pRear->link = P;
	pRear = P;
}

Polynomial Add(Polynomial P1, Polynomial P2)
{
	Polynomial t1, t2, P, Rear, t;
	int sum;
	t1 = P1;
	t2 = P2;
	P = new PolyNode;
	P->link = NULL;
	Rear = P;
	while (t1 && t2)
	{
		if (t1->expon == t2->expon)
		{
			sum = t1->coef + t2->coef;
			if (sum)
				Attach(sum, t1->expon, Rear);
			t1 = t1->link;
			t2 = t2->link;
		}
		else if (t1->expon > t2->expon)
		{
			Attach(t1->coef, t1->expon, Rear);
			t1 = t1->link;
		}
		else
		{
			Attach(t2->coef, t2->expon, Rear);
			t2 = t2->link;
		}
	}
	while (t1)
	{
		Attach(t1->coef, t1->expon, Rear);
		t1 = t1->link;
	}
	while (t2)
	{
		Attach(t2->coef, t2->expon, Rear);
		t2 = t2->link;
	}
	t = P;
	P = P->link;
	delete t;
	return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2)
{
	Polynomial P, Rear, t1, t2, t;
	int c, e;
	if (!P1 || !P2)
		return NULL;

	t1 = P1;
	t2 = P2;
	P = new PolyNode;
	Rear = P;
	while (t2)
	{
		//1式第1项乘2式，得到最初式
		Attach(t1->coef * t2->coef, t1->expon + t2->expon, Rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	// 其余项分别乘2式，并插入
	while (t1)
	{
		t2 = P2;
		Rear = P; //每轮循环要重置
		while (t2)
		{
			c = t1->coef * t2->coef;
			e = t1->expon + t2->expon;
			//在有序多项式中插入新项
			//找插入位置
			while (Rear->link && Rear->link->expon > e)
				Rear = Rear->link;
			if (Rear->link && Rear->link->expon == e)
			{
				if (Rear->link->coef + c) //插入项
					Rear->link->coef += c;
				else
				{ //抵消，删除这一项
					t = Rear->link;
					Rear->link = t->link;
					delete t;
				}
			}
			else
			{
				t = new PolyNode;
				t->coef = c;
				t->expon = e;
				t->link = Rear->link;
				Rear->link = t;
				Rear = Rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = P;
	P = P->link;
	delete t2;
	return P;
}
