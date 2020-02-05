#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x, c = 0; cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (x & 1) c++;
        }
        if (n & 1) cout << (c >= 1 ? "Yes" : "No") << endl;
        else cout << (c >= 1 && c != n ? "Yes" : "No") << endl;
    }
    return 0;
}