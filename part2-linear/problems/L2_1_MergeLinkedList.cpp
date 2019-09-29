#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef int ElementType;
typedef struct Node *PtrToNode;

typedef struct Node
{
	ElementType Data;
	PtrToNode Next;
}node;
typedef PtrToNode List;

node *node_init()
{
	node *head = (node*)malloc(sizeof(node));
	head->Next = NULL;
	return head;
}

void Print(node*head)
{
	node*p = head->Next;
	if (!p) {
		printf("NULL");
		printf("\n");
	}
	else {
		while (p) {
			printf("%5d", p->Data);
			p = p->Next;
		}
		printf("\n");
	}
}

node* node_find(node*head, int n)
{
	int i = 0;
	node *p = head;
	if (n < 0) {
		printf("not\n");
		return NULL;
	}
	else if (n == 0) {
		return head;
	}
	while (p&&i < n) {
		p = p->Next;
		i++;
	}
	if (!p)printf("not\n");
	return p;
}

void node_insert(node*head, int pos, ElementType num)
{
	node*pre = node_find(head, pos - 1), *q;
	if (!pre) {
		printf("not\n");
	}
	else {
		q = (node*)malloc(sizeof(node));
		q->Data = num;
		q->Next = pre->Next;
		pre->Next = q;
	}
}

void node_dele(node*head, int pos)
{
	node*pre = node_find(head, pos - 1), *q;
	if (!pre) {
		printf("not\n");
	}
	else {
		q = pre->Next;
		pre->Next = q->Next;
		free(q);
	}
}

void node_destory(node*head)
{
	node*p = head, *q;
	while (p) {
		q = p->Next;
		free(p);
		p = q;
	}
}
/*
	两个有序链表序列的合并
*/
List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	List p, q, l, tmp;
	p = L1->Next;
	q = L2->Next;
	l = L;
	while (p&&q) {
		if (p->Data <= q->Data) {
			l->Next = p;
			p = p->Next;
		}
		else {
			l->Next = q;
			q = q->Next;
		}
		l = l->Next;
	}
	if (p) {
		l->Next = p;
	}
	if (q) {
		l->Next = q;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	return L;
}
int main(int argc, char const *argv[])
{
	List L1 = node_init();
	List L2 = node_init();
	node_insert(L1, 1, 1);
	node_insert(L1, 2, 3);
	node_insert(L1, 3, 5);
	node_insert(L2, 1, 2);
	node_insert(L2, 2, 4);
	node_insert(L2, 3, 6);
	node_insert(L2, 4, 8);
	node_insert(L2, 5, 10);
	List L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}
