#include <iostream>
#include <algorithm>
using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode {
	int value;
	Tree left, right;
};

Tree newNode(int value);
Tree insert(Tree T, int val);
int getHeight(Tree T);
Tree rotateLL(Tree A);
Tree rotateRR(Tree A);
Tree rotateLR(Tree A);
Tree rotateRL(Tree A);
int find(Tree T, int val);
int main()
{
	int N, a, i;
	cin >> N;
	cin >> a;
	Tree avl = newNode(a);
	for (i = 1; i < N; i++) {
		cin >> a;
		avl = insert(avl, a);
	}
	cout << avl->value << endl;
	return 0;
}

Tree newNode(int value) {
	Tree T = new struct TreeNode;
	T->left = NULL;
	T->right = NULL;
	T->value = value;
	return T;
}
//插入节点
Tree insert(Tree T, int val) {
	if (!T) T = newNode(val);
	else {
		if (val > T->value) {
			T->right = insert(T->right, val);
		}
		else {
			T->left = insert(T->left, val);
		}
	}
	//平衡参数大于1
	if (getHeight(T->left) - getHeight(T->right) > 1) {
		//cout << "发现者: " << T->value << endl;
		if (T->left->left&&find(T->left->left, val))
			T = rotateLL(T);
		else
			T = rotateLR(T);
	}
	if (getHeight(T->left) - getHeight(T->right) < -1) {
		//cout << "发现者: " << T->value << endl;
		if (T->right->right&&find(T->right->right, val))
			T = rotateRR(T);
		else
			T = rotateRL(T);
	}
	return T;
}

int getHeight(Tree T)
{
	if (!T) {
		return 0;
	}
	return 1 + max(getHeight(T->left), getHeight(T->right));
}

Tree rotateLL(Tree A)
{
	//cout << "LL" << endl;
	Tree B = A->left;
	A->left = B->right;
	B->right = A;
	return B;
}

Tree rotateRR(Tree A)
{
	//cout << "RR" << endl;
	Tree B = A->right;
	A->right = B->left;
	B->left = A;
	return B;
}

Tree rotateLR(Tree A)
{
	//cout << "LR" << endl;
	Tree B = A->left;
	Tree C = A->left->right;
	A->left = C->right;
	B->right = C->left;
	C->left = B;
	C->right = A;
	return C;
}

Tree rotateRL(Tree A)
{
	//cout << "RL" << endl;
	Tree B = A->right;
	Tree C = A->right->left;
	A->right = C->left;
	B->left = C->right;
	C->left = A;
	C->right = B;
	return C;
}

int find(Tree T, int val)
{
	if (!T) {
		return 0;
	}
	else {
		if (T->value == val) {
			return 1;
		}
		return max(find(T->left, val), find(T->right, val));
	}
}
