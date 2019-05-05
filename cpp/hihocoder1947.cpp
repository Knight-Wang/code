#include <bits/stdc++.h>
using namespace std;
int in[1005], p[1005];
vector<int> G[1005];
int main()
{
    int n, m, a, b;
    while (cin >> n >> m)
    {
        memset(p, 0, sizeof p);
        memset(in, 0, sizeof in);
        for (int i = 0; i < m; i++) { cin >> a >> b; in[b]++; G[a].push_back(b); }
        queue<int> q;
        q.push(1);
        while (!q.empty())
        {
            int t = q.front(); q.pop();
            for (int i = 0; i < G[t].size(); i++)
            {
                int u = G[t][i];
                in[u]--;
                if (in[u] == 0) { q.push(u); p[u] = t; }
            }
        }
        for (int i = 1; i <= n; i++) cout << p[i] << endl;
    }
    return 0;
}