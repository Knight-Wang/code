#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], tree[N * 4], n, q;
int sum[N][30];

void build(int num, int l, int r)
{
    if (l == r) { tree[num] = a[l]; return; }
    int m = l + r >> 1;
    build(num * 2, l, m);
    build(num * 2 + 1, m + 1, r);
    tree[num] = min(tree[num * 2], tree[num * 2 + 1]);
}

int query(int num, int l, int r, int x, int y)
{
    if (x <= l && y >= r) return tree[num];
    int m = l + r >> 1, ans = 25;
    if (x <= m) ans = min(ans, query(num * 2, l, m, x, y));
    if (y >= m + 1) ans = min(ans, query(num * 2 + 1, m + 1, r, x, y));
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int T, l, r;
    string s;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> q;
        cin >> s;
        for (int i = 0; i < n; i++) a[i + 1] = s[i] - 'A';
        build(1, 1, n);
        memset(sum, 0, sizeof sum);
        for (int j = 1; j <= n; j++)
        {
            int tmp = s[j - 1] - 'A';
            for (int k = 0; k < 26; k++)
                sum[j][k] = sum[j - 1][k];
            sum[j][tmp]++;
        }
        cout << "Case #" << t + 1 << ":" << endl;
        for (int i = 0; i < q; i++) 
        {
            cin >> l >> r;
            int minn = query(1, 1, n, l, r);
            cout << sum[r][minn] - sum[l - 1][minn] << endl;
        }
    }
    return 0;
}