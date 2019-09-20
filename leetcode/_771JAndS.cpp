#include <iostream>
using namespace std;

int numJewelsInStones(string J, string S)
{
    int count = 0;
    for (char &c : S)
    {
        if (J.find(c) != string::npos)
        {
            count += 1;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    string J, S;
    J = "z";
    S = "ZZ";
    cout << numJewelsInStones(J, S)<<endl;
    return 0;
}
