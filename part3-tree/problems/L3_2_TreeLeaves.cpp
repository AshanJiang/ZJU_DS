#include <iostream>
#include <queue>
#include <string>
using namespace std;

constexpr auto MaxTree = 10	;
typedef int Tree;
constexpr auto Null = -1;
//使用静态链表
struct TreeNode {
	int element;
	Tree left;
	Tree right;
}T1[MaxTree];
//创建树并返回根所在位置
Tree BuildTree(struct TreeNode T[]);
string FindLeaves(Tree root);
int main() {
	Tree R1;
	R1 = BuildTree(T1);
	cout << FindLeaves(R1) << endl;
	return 0;
}

Tree BuildTree(TreeNode T[])
{
	int N, i, root = -1;
	char cl, cr;
	cin >> N;
	int *check = new int[N];
	if (N) {
		//检查数组，根节点是没有边指向它的
		for (i = 0; i < N; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			cin >> cl >> cr;
			T[i].element = i;
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

string FindLeaves(Tree root) {
	//层次遍历
	string res = "";
	queue<TreeNode> levelTree;
	levelTree.push(T1[root]);
	while (!levelTree.empty()) {
		if (levelTree.front().left != Null)
			levelTree.push(T1[levelTree.front().left]);
		if (levelTree.front().right != Null)
			levelTree.push(T1[levelTree.front().right]);
		if (levelTree.front().left == Null && levelTree.front().right == Null)
			res += to_string(levelTree.front().element) + ' ';
		levelTree.pop();
	}
	return res.substr(0, res.size() - 1);
}
