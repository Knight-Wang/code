#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int a[N], p[N], cnt[N];
vector<int> v[N];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++) v[i].clear();
        memset(cnt, 0, sizeof cnt);
        int x, y;
        for (int i = 1; i <= n; i++) { cin >> a[i]; p[a[i]] = i; }
        for (int i = 1; i <= m; i++)
        {
            cin >> x >> y;
            v[y].push_back(x);
        }
        for (int i = n; i >= 1; i--)
        {
            for (int j = 0; j < v[a[i]].size(); j++)
            {
                if (p[v[a[i]][j]] < i) cnt[v[a[i]][j]]++;
            }
        }
        vector<pair<int, int>> t;
        for (int i = 0; i < v[a[n]].size(); i++)
        {
            int to = v[a[n]][i];
            t.push_back(make_pair(p[to], to));
        }
        sort(t.begin(), t.end());
        int cur = n, ans = 0;
        for (int i = t.size() - 1; i >= 0; i--)
        {
            x = t[i].second;
            if (cnt[x] == cur - t[i].first)
            {
                ans++; cur--;
                for (int j = 0; j < v[x].size(); j++)
                {
                    int to = v[x][j]; cnt[to]--;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}