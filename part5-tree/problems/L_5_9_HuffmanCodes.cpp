#include <iostream>
#include <string>
using namespace std;
constexpr auto MAX_N = 63;
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int weight;
	HuffmanTree left, right;
};

int main() {
	//N字符数量，f字符频率数组
	int N, f[MAX_N], i;
	//c字符数组
	char c[MAX_N];
	//1.读数据
	cin >> N;
	i = 0;
	while (N--) {
		cin >> c[i];
		cin >> f[i];
		i += 1;
	}
	//2.构造哈夫曼树
	//3.计算最小码长
	//4.读入待检测编码
	//5.比较码长
	//6.根据编码构造哈夫曼树，判断是否在叶子节点上
	return 0;
}
