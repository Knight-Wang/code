#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], b[N], c[N], n, m;
bool check(int x)
{
    memset(c, 0, sizeof c);
    unordered_set<int> st;
    for (int i = 1; i <= m; i++)
    {
        if (a[i] == x || b[i] == x) st.insert(i);
    }
    for (int i = 1; i <= m; i++)
    {
        if (st.count(i)) continue;
        c[a[i]]++; c[b[i]]++;
    }
    bool flg = false;
    for (int i = 1; i <= n; i++)
    {
        if (i == x) continue;
        if (c[i] + st.size() == m) { flg = true; break; }
    }
    return flg;
}
int main()
{
    while (cin >> n >> m)
    {
        for (int i = 1; i <= m; i++) cin >> a[i] >> b[i];
        if (check(a[1]) || check(b[1])) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}