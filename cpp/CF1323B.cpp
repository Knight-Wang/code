#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
const int N = 40005;
int a[N], b[N];
 
void pre(int c[], int l, vi& v)
{
    for (int i = 1; i <= l; i++)
    {
        if (c[i] == 0) continue;
        int j = i;
        while (j <= l && c[j] == 1) j++;
        v.push_back(j - i);
        i = j;
    }
}
 
void work(vi& v1, vi& v2, vi& s1, vi& s2, int x, int y, ll& ans)
{
    int l1 = v1.size(), l2 = v2.size();
    int p1 = lower_bound(v1.begin(), v1.end(), x) - v1.begin();
    int p2 = lower_bound(v2.begin(), v2.end(), y) - v2.begin();
    if (p1 < l1 && p2 < l2)
    {
        int p = s1[p1] - (x - 1) * (l1 - p1);
        int q = s2[p2] - (y - 1) * (l2 - p2);
        ans += (ll)p * q;
    }
}
int main()
{
    int n, m, k;
    while (cin >> n >> m >> k)
    {
        vi v1, v2;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= m; i++) cin >> b[i];
        pre(a, n, v1); pre(b, m, v2);
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        int l1 = v1.size(), l2 = v2.size();
        vi s1(v1.begin(), v1.end()), s2(v2.begin(), v2.end());
        for (int i = l1 - 2; i >= 0; i--) s1[i] = s1[i + 1] + v1[i];
        for (int i = l2 - 2; i >= 0; i--) s2[i] = s2[i + 1] + v2[i];
        ll ans = 0;
        for (int i = 1; i * i <= k; i++)
        {
            if (k % i) continue;
            int t = k / i;
            work(v1, v2, s1, s2, i, t, ans);
            if (i == t) continue;
            work(v1, v2, s1, s2, t, i, ans);
        }
        cout << ans << endl;
    }
    return 0;
}