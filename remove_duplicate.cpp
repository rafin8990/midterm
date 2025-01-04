#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    int value;
    while (cin >> value && value != -1)
    {
        l.push_back(value);
    }

     l.sort();
    l.unique(); 

    for (const int &val : l)
    {
        cout << val << " ";
    }
    return 0;
}
