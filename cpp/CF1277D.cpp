#include <bits/stdc++.h>
using namespace std;
set<string> st[4];
bool work(set<string>& a, set<string>& b, map<string, int>& mp, vector<int>& res)
{
    int d = a.size() - b.size();
    for (auto it: a)
    {
        if (res.size() == d / 2) break;
        string tmp = it;
        reverse(tmp.begin(), tmp.end());
        if (b.count(tmp)) continue;
        res.push_back(mp[it]);
    }
    return res.size() >= d / 2;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        for (int i = 0; i < 4; i++) st[i].clear();
        int n; cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string s; cin >> s;
            mp[s] = i + 1;
            int a = *s.begin() - '0', b = *(s.end() - 1) - '0';
            int p = a * 2 + b;
            st[p].insert(s);
        }
        if (!st[0].empty() && !st[3].empty() && st[1].empty() && st[2].empty())
        {
            cout << -1 << endl; continue;
        }
        vector<int> res;
        bool ok = false;
        if (st[1].size() > st[2].size()) ok = work(st[1], st[2], mp, res);
        else ok = work(st[2], st[1], mp, res);
        if (ok)
        {
            cout << res.size() << endl;
            for (auto it: res) cout << it << " ";
            cout << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}