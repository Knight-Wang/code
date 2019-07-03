#include <bits/stdc++.h>
using namespace std;
const int N = 300005, INF = 0x3f3f3f3f;
deque<int> d[N];
int a[N], b[N], tree[N * 4];
 
void build(int num, int l, int r)
{
    if (l == r) { tree[num] = a[l]; return; }
    int m = l + r >> 1;
    build(num << 1, l, m);
    build(num << 1 | 1, m + 1, r);
    tree[num] = min(tree[num << 1], tree[num << 1 | 1]);
}
 
void update(int num, int l, int r, int x, int y)
{
    if (l == r) { tree[num] = y; return; }
    int m = l + r >> 1;
    if (x <= m) update(num << 1, l, m, x, y);
    else update(num << 1 | 1, m + 1, r, x, y);
    tree[num] = min(tree[num << 1], tree[num << 1 | 1]);
}
 
int query(int num, int l, int r, int x, int y)
{
    if (x <= l && y >= r) return tree[num];
    int m = l + r >> 1;
    int ans = INF;
    if (x <= m) ans = min(ans, query(num << 1, l, m, x, y));
    if (y >= m + 1) ans = min(ans, query(num << 1 | 1, m + 1, r, x, y));
    return ans;
}
 
int main()
{
    int t, n; cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) d[i].clear();
        for (int i = 1; i <= n; i++) { cin >> a[i]; d[a[i]].push_back(i); }
        build(1, 1, n);
        for (int i = 1; i <= n; i++) cin >> b[i];
        bool flg = true;
        int i = 1, j = 1;
        while (i <= n && j <= n)
        {
            while (i <= n && a[i] == INF) i++;
            if (a[i] == b[j]) { d[a[i]].pop_front(); i++; j++; }
            else if (a[i] < b[j]) { flg = false; break; }
            else
            {
                if (d[b[j]].empty()) { flg = false; break; }
                else
                {
                    int t = d[b[j]].front();
                    int minn = query(1, 1, n, i, t);
                    if (minn < a[t]) { flg = false; break; }
                    else
                    {
                        update(1, 1, n, t, INF); a[t] = INF;
                        d[b[j]].pop_front();
                        j++;
                    }
                }
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}