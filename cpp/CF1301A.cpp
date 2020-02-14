#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string a, b, c; cin >> a >> b >> c;
        int n = a.length();
        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == b[i] && a[i] != c[i]) { flg = false; break; }
            else if (a[i] != b[i] && c[i] != a[i] && c[i] != b[i]) { flg = false; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}