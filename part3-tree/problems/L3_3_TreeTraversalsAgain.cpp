#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct TreeNode {
	int left = -1;
	int right = -1;
}T[31];
int ROOT;
void postorderTraversal(int root);
int main()
{
	int N, num, pushNum = -1, popNum = -1;
	string op;
	stack <int> stack;
	cin >> N;
	N *= 2;
	//读入数据
	while (N--) {
		cin >> op;
		if (op == "Push") {
			cin >> num;
			if (pushNum == -1 && popNum == -1)
				ROOT = num;
			if (pushNum != -1) {
				T[pushNum].left = num;
			}
			if (popNum != -1) {
				T[popNum].right = num;
				popNum = -1;
			}
			pushNum = num;
			stack.push(pushNum);
		}
		else {
			pushNum = -1;
			popNum = stack.top();
			stack.pop();
		}
	}
	postorderTraversal(ROOT);
}

void postorderTraversal(int root) {
	if (root != -1) {
		postorderTraversal(T[root].left);
		postorderTraversal(T[root].right);
		if (root == ROOT)
			cout << root << endl;
		else
			cout << root << ' ';
	}
}
