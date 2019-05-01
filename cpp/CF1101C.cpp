#include <bits/stdc++.h>
using namespace std;
struct node
{
    int l, r, id, g;
};
node a[200005];
bool cmp1(node& a, node& b)
{
    if (a.l == b.l) return a.r < b.r;
    return a.l < b.l;
}
bool cmp2(node& a, node& b)
{
    return a.id < b.id;
}
int main()
{
    ios::sync_with_stdio(false);
    int T, n;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i].l >> a[i].r;
            a[i].id = i; a[i].g = 2;
        }
        sort(a, a + n, cmp1);
        int i = 1, now = a[0].r;
        a[0].g = 1;
        for ( ; i < n; i++)
        {
            if (a[i].l > now) break;
            a[i].g = 1;
            now = max(now, a[i].r);
        }
        if (i == n) { cout << -1 << endl; continue; }
        sort(a, a + n, cmp2);
        for (int i = 0; i < n; i++) cout << a[i].g << " ";
        cout << endl;
    }
    return 0;
}