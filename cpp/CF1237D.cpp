#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 300005;
int a[N], st[N][20];
int log2(int x)
{
    int res = -1;
    while (x) { x >>= 1; res++; }
    return res;
}
void init(int n)
{
    for (int i = 0; i < n; i++) st[i][0] = a[i];
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
        }
    }
}
int get_max(int l, int r)
{
    if (l > r) return -INF;
    int p = log2(r - l + 1);
    return max(st[l][p], st[r - (1 << p) + 1][p]);
}
int main()
{
    int n;
    while (cin >> n)
    {
        int minn = INF, maxn = -INF;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i]; a[i + n] = a[i + 2 * n] = a[i];
            minn = min(a[i], minn);
            maxn = max(a[i], maxn);
        }
        init(3 * n);
        vector<int> res(n, -1);
        if (maxn <= minn * 2)
        {
            for (auto it: res) cout << it << " ";
            cout << endl; continue;
        }
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur = max(cur, i + 1);
            int maxn = get_max(i, cur);
            while (cur < 3 * n && a[cur] * 2 >= maxn)
            {
                maxn = max(maxn, a[cur]); cur++;
            }
            res[i] = cur - i;
        }
        for (auto it: res) cout << it << " ";
        cout << endl;
    }
    return 0;
}