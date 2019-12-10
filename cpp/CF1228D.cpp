#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
vector<int> G[N];
int res[N];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++) { res[i] = 0; G[i].clear(); }
        int a, b;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        res[1] = 1;
        set<int> st{G[1].begin(), G[1].end()};
        for (int i = 2; i <= n; i++)
        {
            if (!st.count(i)) res[i] = 1;
        }
        int i = 2;
        for ( ; i <= n; i++)
        {
            if (res[i] != 1) break;
        }
        res[i] = 2;
        set<int> st2{G[i].begin(), G[i].end()};
        for (int j = 2; j <= n; j++)
        {
            if (j == i || res[j] == 1) continue;
            if (st2.count(j)) res[j] = 3;
            else res[j] = 2;
        }
        vector<int> c(4, 0);
        for (int i = 1; i <= n; i++) c[res[i]]++;
        bool flg = true;
        if (!c[1] || !c[2] || !c[3]) flg = false;
        if (m != c[1] * c[2] + c[2] * c[3] + c[3] * c[1]) flg = false;
        for (int i = 1; i <= n; i++)
        {
            int p = res[i];
            for (auto it: G[i])
            {
                if (res[it] == p) { flg = false; break; }
            }
            if (!flg) break;
        }
        if (!flg) { cout << -1 << endl; continue; }
        for (int i = 1; i <= n; i++) cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}