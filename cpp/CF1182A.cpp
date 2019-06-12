#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        if (n & 1) cout << 0 << endl;
        else cout << (1 << (n / 2)) << endl;
    }
    return 0;
}