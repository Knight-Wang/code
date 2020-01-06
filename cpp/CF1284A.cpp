#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        vector<string> a, b; string s;
        for (int i = 0; i < n; i++) { cin >> s; a.push_back(s); }
        for (int i = 0; i < m; i++) { cin >> s; b.push_back(s); }
        int q; cin >> q;
        while (q--)
        {
            int x; cin >> x; x--;
            x %= n * m;
            int cur = 0;
            string res = "";
            int i = 0, j = 0;
            while (cur < n * m)
            {
                if (cur == x) { res = a[i] + b[j]; break; }
                i++;
                if (i == n) i = 0;
                j++;
                if (j == m) j = 0;
                cur++;
            }
            cout << res << endl;
        }
    }
    return 0;
}