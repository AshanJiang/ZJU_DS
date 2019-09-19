#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void printVector(const T &a);
vector<string> shuffle(vector<string> &a, vector<int> &order, vector<string> &b);

int main()
{
  vector<string> a;
  vector<string> suit{"S", "H", "C", "D"};
  vector<string> b(54, "");
  vector<int> order;
  int K, tmp;
  for (size_t i = 0; i < suit.size(); i++)
  {
    for (size_t j = 1; j <= 13; j++)
    {
      a.push_back(suit[i] + to_string(j));
    }
  }
  a.push_back("J1");
  a.push_back("J2");
  
  while (cin >> K)
  {
    for (size_t i = 0; i < 54; i++)
    {
      cin >> tmp;
      order.push_back(tmp);
    }
    for (int i = 0; i < K; i++)
    {
        a = shuffle(a, order, b);
    }
  }

  printVector(a);

  return 0;
}

vector<string> shuffle(vector<string> &a, vector<int> &order, vector<string> &b)
{
  for (size_t i = 0; i < order.size(); i++)
  {
    b.at(order[i] - 1) = a.at(i);
  }
  return b;
}

template <typename T>
void printVector(const T &a)
{
  for (size_t i = 0; i < a.size() - 1; i++)
  {
    cout << a[i] << ' ';
  }
  cout << a.back() << endl;
}