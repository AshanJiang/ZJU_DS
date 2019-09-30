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
int main()
{
	Polynomial P1, P2, PP, PS;
	P1 = ReadPoly();
	P2 = ReadPoly();

	//PP = Mult(P1, P2);
	//PtintPoly(PP);
	//PS = Add(P1, P2);
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
