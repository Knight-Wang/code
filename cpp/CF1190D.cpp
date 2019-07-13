#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 200005;
int n, x[N], y[N], bit[N];
vector<int> v[N];
void compress(vector<int>& x)
{
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
}
int lowbit(int x) { return x & -x; }
void add(int i, int x)
{
    while (i <= n) { bit[i] += x; i += lowbit(i); }
}
int sum(int i)
{
    int ans = 0;
    while (i) { ans += bit[i]; i -= lowbit(i); }
    return ans;
}
int main()
{
    while (cin >> n)
    {
        memset(bit, 0, sizeof bit);
        for (int i = 1; i <= n; i++) v[i].clear();
        vector<int> vx, vy;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i] >> y[i];
            vx.push_back(x[i]); vy.push_back(y[i]);
        }
        compress(vx); compress(vy);
        for (int i = 1; i <= n; i++)
        {
            x[i] = lower_bound(vx.begin(), vx.end(), x[i]) - vx.begin() + 1;
            y[i] = lower_bound(vy.begin(), vy.end(), y[i]) - vy.begin() + 1;
            v[y[i]].push_back(x[i]);
        }
        ll ans = 0;
        for (int i = n; i >= 1; i--)
        {
            sort(v[i].begin(), v[i].end());
            for (int j = 0; j < v[i].size(); j++)
            {
                int t = v[i][j];
                if (sum(t) - sum(t - 1)) continue;
                add(t, 1);
            }
            int prev = 0;
            for (int j = 0; j < v[i].size(); j++)
            {
                int t = v[i][j];
                ans += 1ll * (sum(t - 1) - sum(prev) + 1) * (sum(n) - sum(t) + 1);
                prev = t;
            }
        }
        cout << ans << endl;
    }
    return 0;
}