#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string p, h;
        cin >> p >> h;
        sort(p.begin(), p.end());
        int n = p.length(), m = h.length();
        if (n > m) { cout << "NO" << endl; continue; }
        bool flg = false;
        for (int i = 0; i <= m - n; i++)
        {
            string tmp = h.substr(i, n);
            sort(tmp.begin(), tmp.end());
            if (tmp == p) { flg = true; break; }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}