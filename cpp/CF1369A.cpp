#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int x; cin >> x;
        int t = x % 4;
        if (t) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}