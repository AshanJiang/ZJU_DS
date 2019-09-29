#include <iostream>
using namespace std;

typedef int ElementType;
typedef struct LNode *List;

struct LNode
{
	ElementType Data;
	List next;
};

int Length(List PtrL) {
	List p = PtrL;
	int j = 0;
	while (p) {
		p = p->next;
		j++;
	}
	return j;
}

List FindKth(int K, List PtrL){
	List p = PtrL;
	int i = 1;
	while (p != NULL && i < K) {
		p = p->next;
		i++;
	}
	if (i == K) return p;
	else return NULL;
}

List Find(ElementType X, List PtrL) {
	List p = PtrL;
	while (p != NULL && p->Data != X)
		p = p->next;
	return p;
}

List Insert(ElementType X, int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = new LNode;
		s->Data = X;
		s->next = PtrL;
		return s;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL) {
		cout << "参数错误" << endl;
		return NULL;
	}
	else {
		s = new LNode;
		s->Data = X;
		s->next = p->next;
		p->next = s;
		return PtrL;
	}
}

List Delete(int i, List PtrL) {
	List p, s;
	if (i == 1) {
		s = PtrL;
		if (PtrL != NULL) PtrL = PtrL->next;
		else return NULL;
		delete s;
		return PtrL;
	}
	p = FindKth(i - 1, PtrL);
	if (p == NULL) {
		cout << "第" << i - 1 << "个节点不存在" << endl;
		return NULL;
	}
	else if (p->next == NULL) {
		cout << "第" << i << "个节点不存在" << endl;
		return NULL;
	}
	else {
		s = p->next;	
		p->next = s->next;
		delete s;
		return PtrL;
	}
}

int main(int argc, char const *argv[])
{
	List myList = new LNode;
	myList->Data = 10;
	myList->next = NULL;
	for (int i = 9; i > 0; i--)
	{
		myList = Insert(i, 1, myList);
	}
	Delete(2, myList);

	return 0;
}
