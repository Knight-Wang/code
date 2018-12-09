#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 500005;
int a[N], tree[N * 4], n;

void update(int num, int l, int r, int x, int dx)
{
    if (l == r) { tree[num] += dx; return; }
    int m = l + r >> 1;
    if (x <= m) update(num * 2, l, m, x, dx);
    else update(num * 2 + 1, m + 1, r, x, dx);
    tree[num] = tree[num * 2] + tree[num * 2 + 1];
}

int query(int num, int l, int r, int x, int y)
{
    if (x <= l && y >= r) return tree[num];
    int m = l + r >> 1, ans = 0;
    if (x <= m) ans += query(num * 2, l, m, x, y);
    if (y >= m + 1) ans += query(num * 2 + 1, m + 1, r, x, y);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    int n;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        memset(tree, 0, sizeof tree);
        vector<int> v;
        for (int i = 1; i <= n; i++) v.push_back(a[i]);
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
        for (int i = 1; i <= n; i++)
        {
            a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
        }
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += query(1, 1, n, a[i] + 1, n);
            update(1, 1, n, a[i], 1);
        }
        cout << ans << endl;
    }
    return 0;
}