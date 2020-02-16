#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        string ans = "";
        map<string, int> mp;
        for (int i = 0; i < n; i++)
        {
            string s; cin >> s; string t = s;
            reverse(s.begin(), s.end());
            if (s == t)
            {
                int l = t.length();
                if ((int)t.length() > (int)ans.length()) ans = t;
            }
            else
            {
                mp[t]++;
            }
        }
        string res = "";
        for (auto it: mp)
        {
            string t = it.first;
            reverse(t.begin(), t.end());
            if (mp.count(t))
            {
                int maxn = min(mp[t], it.second);
                for (int i = 0; i < maxn; i++)
                {
                    res += it.first;
                }
                mp.erase(t);
            }
        }
        string f = res;
        reverse(f.begin(), f.end());
        res += ans + f;
        cout << res.length() << endl;
        cout << res << endl;
    }
    return 0;
}