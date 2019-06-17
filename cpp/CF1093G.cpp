#include <bits/stdc++.h>
using namespace std;
const int N = 200005, K = 5, INF = 0x3f3f3f3f;
int a[N][K], b[K], tree[N * 4][1 << K][2], n, k;

void build(int num, int l, int r)
{
    if (l == r)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            int sum = 0;
            for (int d = 0; d < k; d++)
            {
                if ((i >> d) & 1) sum += a[l][d];
                else sum -= a[l][d];
            }
            tree[num][i][0] = tree[num][i][1] = sum;
        }
        return;
    }
    int m = l + r >> 1;
    build(num << 1, l, m);
    build(num << 1 | 1, m + 1, r);
    for (int i = 0; i < (1 << k); i++)
    {
        tree[num][i][1] = max(tree[num << 1][i][1], tree[num << 1 | 1][i][1]);
        tree[num][i][0] = min(tree[num << 1][i][0], tree[num << 1 | 1][i][0]);
    }
}

void update(int num, int l, int r, int x)
{
    if (l == r)
    {
        for (int i = 0; i < (1 << k); i++)
        {
            int sum = 0;
            for (int d = 0; d < k; d++)
            {
                if ((i >> d) & 1) sum += b[d];
                else sum -= b[d];
            }
            tree[num][i][0] = tree[num][i][1] = sum;
        }
        return;
    }
    int m = l + r >> 1;
    if (x <= m) update(num << 1, l, m, x);
    else update(num << 1 | 1, m + 1, r, x);
    for (int i = 0; i < (1 << k); i++)
    {
        tree[num][i][1] = max(tree[num << 1][i][1], tree[num << 1 | 1][i][1]);
        tree[num][i][0] = min(tree[num << 1][i][0], tree[num << 1 | 1][i][0]);
    }
}

int query(int num, int l, int r, int x, int y, int t, int id)
{
    if (x <= l && y >= r) return tree[num][id][t];
    if (y < l || x > r) return t ? -INF : INF;
    int m = l + r >> 1, ans = t ? -INF : INF;
    if (x <= m)
    {
        if (t) ans = max(ans, query(num << 1, l, m, x, y, t, id));
        else ans = min(ans, query(num << 1, l, m, x, y, t, id));
    }
    if (y >= m + 1)
    {
        if (t) ans = max(ans, query(num << 1 | 1, m + 1, r, x, y, t, id));
        else ans = min(ans, query(num << 1 | 1, m + 1, r, x, y, t, id));
    }
    return ans;
}

int main()
{
    int q, t, x, l, r;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &a[i][j]);
    build(1, 1, n);
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &x);
            for (int i = 0; i < k; i++) scanf("%d", &b[i]);
            update(1, 1, n, x);
        }
        else
        {
            scanf("%d %d", &l, &r);
            int ans = -INF;
            for (int i = 0; i < (1 << k); i++)
            {
                int maxn = query(1, 1, n, l, r, 1, i);
                int minn = query(1, 1, n, l, r, 0, i);
                ans = max(ans, maxn - minn);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}