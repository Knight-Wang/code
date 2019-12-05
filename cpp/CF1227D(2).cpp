#include <bits/stdc++.h>
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
typedef pair<int, int> pii;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
bool cmp(pii& a, pii& b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second; 
}
 
int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    while (cin >> n)
    {
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
        ordered_set st;
        for (int i = 0; i < n; i++)
        {
            st.insert(b[i].second);
            while (cur < m && i + 1 == sorted_q[cur].first)
            {
                res[sorted_q[cur]] = *st.find_by_order(sorted_q[cur].second - 1);
                cur++;
            }
        }
        for (auto it: q)
        {
            cout << a[res[it] - 1] << endl;
        }
    }
}