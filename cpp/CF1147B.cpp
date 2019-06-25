#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
bool check(int i, int n, set<pii>& st)
{
    for (auto it: st)
    {
        pii t(it.first + i, it.second + i);
        if (t.first > n) t.first %= n;
        if (t.second > n) t.second %= n;
        if (t.first > t.second) swap(t.first, t.second);
        if (!st.count(t)) return false;
    }
    return true;
}
int main()
{
    int n, m, a, b;
    while (cin >> n >> m)
    {
        set<pii> st;
        for (int i = 1; i <= m; i++)
        {
            cin >> a >> b;
            st.insert(make_pair(min(a, b), max(a, b)));
        }
        bool flg = false;
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                if (check(i, n, st)) { flg = true; break; }
                else if (i != 1 && check(n / i, n, st)) { flg = true; break; }
            }
        }
        cout << (flg ? "Yes" : "No") << endl;
    }
    return 0;
}
