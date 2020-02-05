#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    map<int, pair<int, int>> mp;
    mp['L'] = make_pair(-1, 0);
    mp['R'] = make_pair(1, 0);
    mp['U'] = make_pair(0, 1);
    mp['D'] = make_pair(0, -1);
    while (t--)
    {
        int n; string s; cin >> n >> s;
        map<pair<int, int>, int> mp2;
        pair<int, int> cur(0, 0);
        mp2[cur] = -1;
        int minn = n + 1, l = -1, r = -1;
        for (int i = 0; i < n; i++)
        {
            cur.first += mp[s[i]].first;
            cur.second += mp[s[i]].second;
            if (mp2.count(cur))
            {
                int t = i - mp2[cur];
                if (t < minn)
                {
                    minn = t;
                    l = mp2[cur] + 1; r = i;
                }
            }
            mp2[cur] = i;
        }
        if (l == -1 && r == -1) cout << -1 << endl;
        else cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}