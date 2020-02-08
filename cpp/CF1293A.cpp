#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, s, k, x; cin >> n >> s >> k;
        set<int> st;
        for (int i = 0; i < k; i++) { cin >> x; st.insert(x); }
        bool flg = false;
        int i = s, res = INF;
        for ( ; i <= n; i++)
        {
            if (!st.count(i)) { flg = true; break; }
        }
        if (flg) res = min(res, i - s);
        i = s; flg = false;
        for ( ; i >= 1; i--)
        {
            if (!st.count(i)) { flg = true; break; }
        }
        if (flg) res = min(res, s - i);
        cout << res << endl;
    }
    return 0;
}