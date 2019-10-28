#include <iostream>
#include <string>
#include "main.h"
using namespace std;
constexpr auto MAX_N = 63;
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int weight;
	HuffmanTree left = NULL, right = NULL;
};
//最小堆
typedef struct HNode *MinHeap;
struct HNode {
	HuffmanTree *data;
	int size;
};
MinHeap initMinHeap();
void insertHeap(MinHeap H, HuffmanTree T);
int main() {
	//N字符数量，f字符频率数组
	int N, f[MAX_N], i, j;
	//c字符数组
	char c[MAX_N];
	//1.读数据
	cin >> N;
	i = 0;
	j = N;
	while (j--) {
		cin >> c[i];
		cin >> f[i];
		i += 1;
	}
	//2.1构造最小堆
	MinHeap minHeap = initMinHeap();
	for (i = 0; i < N; i++) {
		HuffmanTree t = new TreeNode;
		t->weight = f[i];
		insertHeap(minHeap, t);
	}
	//2.2构造哈夫曼树
	//3.计算最小码长
	//4.读入待检测编码
	//5.比较码长
	//6.根据编码构造哈夫曼树，判断是否在叶子节点上
	return 0;
}

MinHeap initMinHeap()
{
	MinHeap minHeap = new HNode;
	minHeap->size = 0;
	minHeap->data = new HuffmanTree[MAX_N + 1];
	HuffmanTree t = new TreeNode;
	t->weight = 0;
	minHeap->data[0] = t;
	return minHeap;
}

void insertHeap(MinHeap H, HuffmanTree T) {
	int i;
	i = ++H->size;
	for (; H->data[i / 2]->weight > T->weight; i /= 2)
		H->data[i] = H->data[i / 2];
	H->data[i] = T;
}