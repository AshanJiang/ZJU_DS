#include <iostream>
using namespace std;

typedef struct PolyNode *Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};

Polynomial ReadPoly();
void PrintPoly();
void Attach(int c, int e, Polynomial &pRear);
Polynomial Add(Polynomial P1, Polynomial P2);
int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();
	//PP = Mult(P1, P2);
	//PtintPoly(PP);
	PS = Add(P1, P2);
	//PrintPoly(PS);
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
	while (N--) {
		cin >> c >> e;
		Attach(c, e, Rear);
	}
	t = P; P = P->link; delete t;
	return P;
}

void PrintPoly()
{
}

void Attach(int c, int e, Polynomial & pRear)
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
	t1 = P1; t2 = P2;
	P = new PolyNode; P->link = NULL;
	Rear = P;
	while (t1&&t2)
	{
		if (t1->expon == t2->expon) {
			Attach(t1->coef + t2->coef, t1->expon, Rear);
			t1 = t1->link; t2 = t2->link;
		}
		else if (t1->expon > t2->expon) {
			Attach(t1->coef, t1->expon, Rear);
			t1 = t1->link;
		}
		else {
			Attach(t2->coef, t2->expon, Rear);
			t2 = t2->link;
		}
	}
	while (t1) {
		Attach(t1->coef, t1->expon, Rear);
		t1 = t1->link;
	}
	while (t2) {
		Attach(t2->coef, t2->expon, Rear);
		t2 = t2->link;
	}
	t = P; P = P->link; delete t;
	return P;
}
