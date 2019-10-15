#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string>
using namespace std;
typedef struct TNode *Tree;
struct TNode
{
    int data;
    Tree left;
    Tree right;
};
//每层满节点数
int levleTab[11];
int findMiddle(int n);
Tree buildTree(vector<int> v);
Tree newNode(int data);
template <typename T>
vector<T> slice(vector<T> const &v, int m, int n);
string levelorderTraversal(Tree BT);
int main()
{
    int N, a, i;
    Tree T;
    for (i = 0; i < 11; i++)
    {
        levleTab[i] = (int)(pow(2, i + 1) - 1);
    }
    cin >> N;
    vector<int> v;
    while (N--)
    {
        cin >> a;
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    T = buildTree(v);
    cout << levelorderTraversal(T) << endl;
    return 0;
}
//给出中心位置
int findMiddle(int n)
{
    int i = 0, leftNum = 0;
    if (n == 1)
        return 0;
    while (n > levleTab[i])
        i++;
    //最后一层满节点数
    int full = (int)pow(2, i);
    //最后一层节点数
    int lastLevel = full - (levleTab[i] - n);
    //左孩子节点数
    if (lastLevel > full / 2)
        leftNum = (levleTab[i - 1] - 1) / 2 + full / 2;
    else
        leftNum = (levleTab[i - 1] - 1) / 2 + lastLevel;
    return leftNum;
}

Tree buildTree(vector<int> v)
{
    Tree tree;
    if (v.size() == 0)
        return NULL;
    else
    {
        int middle = findMiddle(v.size());
        tree = newNode(v.at(middle));
        vector<int> left = slice(v, 0, middle);
        vector<int> right = slice(v, middle + 1, v.size());
        tree->left = buildTree(left);
        tree->right = buildTree(right);
    }
    return tree;
}

Tree newNode(int data)
{
    Tree T = new struct TNode;
    T->left = NULL;
    T->right = NULL;
    T->data = data;
    return T;
}

string levelorderTraversal(Tree BT)
{
    string res = "";
    queue<Tree> levelTree;
    levelTree.push(BT);
    while (!levelTree.empty())
    {
        if (levelTree.front()->left != NULL)
            levelTree.push(levelTree.front()->left);
        if (levelTree.front()->right != NULL)
            levelTree.push(levelTree.front()->right);
        res += to_string(levelTree.front()->data) + ' ';
        levelTree.pop();
    }
    return res.substr(0, res.size() - 1);
}

template <typename T>
vector<T> slice(vector<T> const &v, int m, int n)
{
    if (m > n)
        return {};
    else
    {
        auto first = v.cbegin() + m;
        auto last = v.cbegin() + n;
        vector<T> vec(first, last);
        return vec;
    }
}
