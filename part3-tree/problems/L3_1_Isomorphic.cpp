#include <iostream>
using namespace std;

constexpr auto MaxTree = 10	;
typedef char ElementType;
typedef int Tree;
constexpr auto Null = -1;
//使用静态链表
struct TreeNode {
	ElementType element;
	Tree left;
	Tree right;
}T1[MaxTree], T2[MaxTree];
//创建树并返回根所在位置
Tree BuildTree(struct TreeNode T[]);
int Isomorphic(Tree R1, Tree R2);
int main() {
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if (Isomorphic(R1, R2)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}

Tree BuildTree(TreeNode T[])
{
	int N, i, root = -1;
	char element, cl, cr;
	cin >> N;
	int *check = new int[N];
	if (N) {
		//检查数组，根节点是没有边指向它的
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			cin >> element >> cl >> cr;
			T[i].element = element;
			if (cl != '-') {
				//char to int
				T[i].left = cl - '0';
				check[T[i].left] = 1;
			}
			else {
				T[i].left = Null;
			}
			if (cr != '-') {
				T[i].right = cr - '0';
				check[T[i].right] = 1;
			}
			else {
				T[i].right = Null;
			}
		}
		for (i = 0; i < N; i++)
			if (!check[i]) break;
		root = i;
	}
	return root;
}

int Isomorphic(Tree R1, Tree R2) {
	//都是空树
	if ((R1 == Null) && (R2 == Null))
		return 1;
	//有一棵空树
	if (((R1 == Null) && (R2 != Null)) || ((R1 != Null) && (R2 == Null))) {
		return 0;
	}
	//根不一样
	if (T1[R1].element != T2[R2].element) {
		return 0;
	}
	//只有右子树
	if ((T1[R1].left == Null) && (T2[R2].left == Null)) {
		return Isomorphic(T1[R1].right, T2[R2].right);
	}
	//左孩子存在且相同
	if (((T1[R1].left != Null) && (T2[R2].left != Null)) && ((T1[T1[R1].left].element) == (T2[T2[R2].left].element))) {
		//直接比较左子树和右子树
		return (Isomorphic(T1[R1].left, T2[R2].left) && Isomorphic(T1[R1].right, T2[R2].right));
	}
	//其他所有情况都可以用左右互换比较来交换到前面的几种情况
	else {
		return (Isomorphic(T1[R1].left, T2[R2].right) && Isomorphic(T1[R1].right, T2[R2].left));
	}
}
