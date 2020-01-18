#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int INF = 0x3f3f3f3f;
int a[N], p[N], s[N], tree[N * 8];
 
void update(int num, int l, int r, int x, int y)
{
    if (l == r) { tree[num] = y; return; }
    int m = l + r >> 1;
    if (x <= m) update(num << 1, l, m, x, y);
    else update(num << 1 | 1, m + 1, r, x, y);
    tree[num] = max(tree[num << 1], tree[num << 1 | 1]);
}
 
int query(int num, int l, int r, int x, int y)
{
    if (x <= l && y >= r) return tree[num];
    int m = l + r >> 1;
    int ans = -INF;
    if (x <= m) ans = max(ans, query(num << 1, l, m, x, y));
    if (y >= m + 1) ans = max(ans, query(num << 1 | 1, m + 1, r, x, y));
    return ans;
}
 
bool check(int i, int j, int maxn, int maxt)
{
    int t = query(1, 1, maxt, maxn, maxt);
    return t >= (j - i + 1);
}
 
int main()
{
    ios::sync_with_stdio(false);
    int t, n, m; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; i++) cin >> p[i] >> s[i];
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(a[i]);
        for (int i = 1; i <= m; i++) v.push_back(p[i]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++)
        {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        for (int i = 1; i <= m; i++)
        {
            p[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin() + 1;
        }
        int maxa = *max_element(a + 1, a + n + 1);
        int maxp = *max_element(p + 1, p + m + 1);
        if (maxa > maxp) { cout << -1 << endl; continue; }
        map<int, int> mp;
        for (int i = 1; i <= m; i++)
        {
            mp[p[i]] = max(mp[p[i]], s[i]);
        }
        for (int i = 0; i <= 4 * (n + m); i++) tree[i] = 0;
        for (auto it: mp)
        {
            update(1, 1, n + m, it.first, it.second);
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i, maxn = a[i];
            while (j <= n && check(i, j, maxn, n + m))
            {
                if (j + 1 <= n) maxn = max(maxn, a[j + 1]);
                j++;
            }
            res++;
            i = j - 1;
        }
        cout << res << endl;
    }
    return 0;
}