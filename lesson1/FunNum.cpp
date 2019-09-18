#include <iostream>

using namespace std;

int main()
{
  string a;
  while (cin >> a)
  {
    string res = "";
    //进位标志
    int carryFlag = 0, digit, insertNum; //字符串手算乘法
    for (int i = a.size() - 1; i >= 0; --i)
    {
      digit = ((int)a.at(i) - 48) * 2 + carryFlag;
      insertNum = digit % 10;
      carryFlag = 0;
      if (digit / 10 > 0)
      {
        carryFlag = 1;
        res.insert(0, 1, static_cast<char>(insertNum + 48));
        if (i == 0)
        {
          res.insert(0, 1, '1');
        }
      }
      else
      {
        res.insert(0, 1, static_cast<char>(insertNum + 48));
      }
    }
    if (a.size() != res.size())
    {
      cout << "No" << endl;
    }
    else
    {
      for (char &c : res)
      {
        if (a.find(c) != string::npos)
        {
          // cout << "delete: " << c << endl;
          a.erase(a.find(c), 1);
          // cout << "after delete: " << a << endl;
        }
      }
      if (a.size() == 0)
      {
        cout << "Yes" << endl;
      }
      else
      {
        cout << "No" << endl;
      }
    }
    cout << res << endl;
  }

  return 0;
}