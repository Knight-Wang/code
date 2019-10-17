#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    long long x, y;
    while (t--)
    {
        cin >> x >> y;
        if (x == y + 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}