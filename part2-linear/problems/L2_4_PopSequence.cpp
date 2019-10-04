#include <iostream>
#include <string>
using namespace std;

int main()
{
	//M栈大小，N输入序列长度，K检查序列数
	//top指的是空位
	int M, N, K, top, i, a;
	//是否空读
	bool flag = false;
	cin >> M >> N >> K;
	int *s = new int [M];
	string res = "";
	while (K--) {
		top = 0;
		i = 1;
		flag = false;
		for (int j = 0; j < N; j++) {
			//检查序列
			cin >> a;
			if (!flag) {
				if (i <= a) {
					//还未入栈
					for (; i <= a; i++) {
						if (top < M) {
							s[top] = i;
							top++;
						}
						//栈爆掉了
						else {
							res.append("NO\n");
							flag = true;
							break;
						}
					}
					//入栈后立刻出栈，输出这个数
					top--;
				}
				else {
					//已经入栈过的元素
					if (s[top - 1] == a) {
						top--;
					}
					else {
						res.append("NO\n");
						flag = true;
					}
				}
			}
			if (j == N - 1 && !flag) {
				res.append("YES\n");
			}
		}
	}
	cout << res.substr(0, res.size() - 1);
	return 0;
}
