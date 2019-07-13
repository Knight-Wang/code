#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const char c[] = {'m', 's', 'p'};
int main()
{
    string s;
    while (getline(cin, s))
    {
        stringstream ss(s);
        string t;
        map<string, int> mp;
        while (ss >> t)
        {
            if (!mp.count(t)) mp[t] = 0;
            mp[t]++;
        }
        int ans = INF;
        for (auto it: mp)
        {
            ans = min(ans, it.second >= 3 ? 0 : 3 - it.second);
        }
        for (int i = 1; i <= 7; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int r = 3;
                if (mp.count(to_string(i) + c[j])) r--;
                if (mp.count(to_string(i + 1) + c[j])) r--;
                if (mp.count(to_string(i + 2) + c[j])) r--;
                ans = min(ans, r);
            }
        }
        cout << ans << endl;
    }
    return 0;
}