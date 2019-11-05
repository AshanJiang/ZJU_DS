#include <iostream>
#include <string>
using namespace std;
constexpr auto MAX_N = 63;
typedef struct TreeNode *HuffmanTree;
struct TreeNode {
	int weight = 0;
	HuffmanTree left = NULL, right = NULL;
};
//最小堆
typedef struct HNode *MinHeap;
struct HNode {
	HuffmanTree *data;
	int size;
};
int CODE_LEN;
MinHeap initMinHeap();
void insertHeap(MinHeap H, HuffmanTree T);
HuffmanTree deleteMin(MinHeap H);
HuffmanTree initHuffman(MinHeap H);
void countCodeLen(HuffmanTree T, int count);
bool createTestTree(HuffmanTree T, string code);
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
	HuffmanTree hTree = initHuffman(minHeap);
	//3.计算最小码长
	CODE_LEN = 0;
	countCodeLen(hTree, 0);
	//4.读入待检测编码code[i]最长为N-1
	int M;
	char tmp;
	string codes[MAX_N];
	cin >> M;
	for (int i = 0; i < M; i++) {
		bool flag = true;
		int testCodeLen = 0; //输入编码码长
		for (int j = 0; j < N; j++) {
			//假设按照顺序输入，否则需要查找
			cin >> tmp;
			cin >> codes[j];
			testCodeLen += codes[j].length()*f[j];
		}
		//5.比较码长
		if (testCodeLen != CODE_LEN) {
			cout << "No" << endl;
		}
		else {
			HuffmanTree testTree = new TreeNode;
			for (int i = 0; i < N; i++)
			{
				//6.根据编码构造哈夫曼树，判断是否在叶子节点上
				if (!createTestTree(testTree, codes[i])) {
					flag = false;
					cout << "No" << endl;
					break;
				}
			}
			if (flag) cout << "Yes" << endl;
		}
	}
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
	for (; H->data[i / 2]->weight > T->weight; i /= 2) //如果插入小值，往上调整
		H->data[i] = H->data[i / 2];
	H->data[i] = T;
}

HuffmanTree deleteMin(MinHeap H) {
	HuffmanTree minItem = H->data[1];
	HuffmanTree X = H->data[H->size--]; //拿最后一个元素作为替换元素
	int parent, child;
	for (parent = 1; parent * 2 <= H->size; parent = child) {
		child = parent * 2;
		if (child != H->size&&H->data[child]->weight > H->data[child + 1]->weight)
			child++; //child指向左右孩子较小值
		if (X->weight <= H->data[child]->weight)
			break;
		else
			H->data[parent] = H->data[child];
	}
	H->data[parent] = X;
	return minItem;
}

HuffmanTree initHuffman(MinHeap H) {
	int i, n; HuffmanTree T;
	n = H->size;
	//循环堆大小(size-1)次
	for (i = 1; i < n; i++) {
		T = new TreeNode;
		T->left = deleteMin(H);
		T->right = deleteMin(H);
		T->weight = T->left->weight + T->right->weight;
		insertHeap(H, T);
	}
	T = deleteMin(H);
	return T;
}

void countCodeLen(HuffmanTree T, int count) {
	if (T) {
		if (T->left == NULL && T->right == NULL) {
			CODE_LEN += T->weight*count;
		}
		countCodeLen(T->left, count + 1);
		countCodeLen(T->right, count + 1);
	}
}
//检查是否是前缀码
bool createTestTree(HuffmanTree T, string code) {
	HuffmanTree tmp = T;
	for (std::string::size_type i = 0; i < code.size(); i++) {
		if (code[i] == '0') {
			if (tmp->left) {
				tmp = tmp->left;
				if (tmp->weight != 0) {
					return false;
				}
			}
			else {
				tmp->left = new TreeNode;
				tmp = tmp->left;
			}
		}
		//=='1'
		else {
			if (tmp->right) {
				tmp = tmp->right;
				if (tmp->weight != 0) {
					return false;
				}
			}
			else {
				tmp->right = new TreeNode;
				tmp = tmp->right;
			}
		}
	}
	if (tmp->right == NULL && tmp->left == NULL)
		return true;
	else
		return false;
}
