#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n;
        map<int, int> mp;
        vector<int> a;
        for (int i = 0; i < n; i++)
        {
            cin >> x; mp[x]++; a.push_back(x);
        }
        int res = 0;
        for (auto& it: mp)
        {
            if (it.second == 1) { res = it.first; break; }
        }
        if (res)
        {
            int idx = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == res) { idx = i + 1; break; }
            }
            cout << idx << endl;
        }
        else cout << -1 << endl;
    }
    return 0;
}