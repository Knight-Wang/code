#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n, m, t, l, r;
    while (cin >> n >> m)
    {
        vector<pii> v1, v2;
        for (int i = 0; i < m; i++)
        {
            cin >> t >> l >> r;
            if (t) v1.push_back(make_pair(l, r));
            else v2.push_back(make_pair(l, r));
        }
        sort(v1.begin(), v1.end());
        vector<pii> x;
        for (int i = 0; i < v1.size(); i++)
        {
            if (x.empty() || v1[i].first > x.back().second) x.push_back(v1[i]);
            else x.back().second = max(x.back().second, v1[i].second);
        }
        bool flg = true;
        for (auto it: v2)
        {
            if (!flg) break;
            for (auto it1: x)
            {
                if (it.first >= it1.first && it.second <= it1.second) { flg = false; break; }
            }
        }
        if (!flg) { cout << "NO" << endl; continue; }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) ans[i] = n - i;
        for (auto it: x)
        {
            sort(ans.begin() + it.first - 1, ans.begin() + it.second);
        }
        cout << "YES" << endl;
        for (auto it: ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}