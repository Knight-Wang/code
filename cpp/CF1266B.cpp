#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        long long x; cin >> x;
        if (x < 15) { cout << "NO" << endl; continue; }
        long long r = x % 14;
        if (r == 0 || r > 6) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}