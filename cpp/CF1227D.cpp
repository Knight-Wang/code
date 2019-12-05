#include <bits/stdc++.h>
 
using namespace std;
const int MAXN = 200000;
typedef pair<int, int> pii;
 
int a[MAXN + 5], bit[MAXN + 5];
 
int lowbit(int x) { return x & -x; }
 
void add(int i, int x)
{
    while (i <= MAXN) { bit[i] += x; i += lowbit(i); }
}
 
int sum(int i)
{
    int ans = 0;
    while (i) { ans += bit[i]; i -= lowbit(i); }
    return ans;
}
 
bool cmp(pii& a, pii& b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second; 
}
 
void work(pii& q, map<pii, int>& mp)
{
    int k = q.first, p = q.second;
    int l = 1, r = MAXN, res = -1;
    while (l <= r)
    {
        int m = l + r >> 1;
        if (sum(m) < p) l = m + 1;
        else { res = m; r = m - 1; }
    }
    assert(res != -1);
    mp[q] = res;
}
 
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n)
    {
        memset(bit, 0, sizeof bit);
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<pii> b(n);
        for (int i = 0; i < n; i++) { b[i].first = a[i]; b[i].second = i + 1; }
        sort(b.begin(), b.end(), cmp);
        cin >> m;
        vector<pii> q(m);
        for (int i = 0; i < m; i++) cin >> q[i].first >> q[i].second;
        vector<pii> sorted_q(q.begin(), q.end());
        sort(sorted_q.begin(), sorted_q.end());
        map<pii, int> res;
        int cur = 0;
        for (int i = 0; i < n; i++)
        {
            add(b[i].second, 1);
            while (cur < m && i + 1 == sorted_q[cur].first)
            {
                work(sorted_q[cur], res);
                cur++;
            }
        }
        for (auto it: q)
        {
            int id = res[it];
            cout << a[id - 1] << endl;
        }
    }
    return 0;
}
