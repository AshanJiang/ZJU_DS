#include <iostream>

using namespace std;

typedef struct TreeNode *Tree;
struct TreeNode {
	int v;
	Tree left, right;
	int flag;
};
Tree makeTree(int N);
Tree newNode(int V);
Tree insert(Tree T, int V);
int judge(Tree T, int N);
int check(Tree T, int V);
void resetT(Tree T);
void freeTree(Tree T);

int main()
{
	int N, L, i;
	Tree T;
	cin >> N;
	while (N) {
		cin >> L;
		//构造树
		T = makeTree(N);
		//其余的和构造的树进行判别
		for (i = 0; i < L; i++) {
			if (judge(T, N))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
			resetT(T);
		}
		freeTree(T);
		cin >> N;
	}
	return 0;
}

Tree makeTree(int N)
{
	Tree T;
	int i, V;
	cin >> V;
	T = newNode(V);
	for (i = 1; i < N; i++) {
		cin >> V;
		T = insert(T, V);
	}
	return T;
}

Tree newNode(int V)
{
	Tree T = new struct TreeNode;
	T->v = V;
	T->left = T->right = NULL;
	T->flag = 0;
	return T;
}

Tree insert(Tree T, int V)
{
	if (!T) T = newNode(V);
	else {
		if (V > T->v)
			T->right = insert(T->right, V);
		else
			T->left = insert(T->left, V);
	}
	return T;
}

int judge(Tree T, int N)
{
	//flag=0目前一致，flag=1已经有不一致
	int i, V, flag = 0;
	cin >> V;
	if (V != T->v) flag = 1;
	else T->flag = 1;
	for (i = 1; i < N; i++) {
		cin >> V; //保证会读完一整行
		if ((!flag) && (!check(T, V))) flag = 1; //检测到新的不一致
	}
	if (flag) return 0;
	else return 1;
	return 0;
}

int check(Tree T, int V)
{
	//flag=1查找过了
	if (T->flag) {
		if (V < T->v) return check(T->left, V);
		if (V > T->v) return check(T->right, V);
		else return 0; //插入了同样的数
	}
	//没找过的节点，相当于挂一个新节点
	else {
		//“正要”挂上去的节点正好是这个没被找过的结点
		if (V == T->v) {
			T->flag = 1;
			return 1;
		}
		//否则本因在这里插入节点，说明新序列和旧树不一样
		else return 0;
	}
	return 0;
}

void resetT(Tree T)
{
	if (T->left) resetT(T->left);
	if (T->right) resetT(T->right);
	T->flag = 0;
}

void freeTree(Tree T)
{
	if (T->left) freeTree(T->left);
	if (T->right) freeTree(T->right);
	delete T;
}
