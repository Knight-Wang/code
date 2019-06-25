#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    while (cin >> n >> k)
    {
        map<int, set<int>> mp;
        for (int i = 1; i <= k; i++)
        {
            cin >> x;
            if (!mp.count(x)) mp[x] = set<int>();
            if (x > 1 && mp.count(x - 1)) mp[x - 1].insert(x);
            if (x < n && mp.count(x + 1)) mp[x + 1].insert(x);
        }
        if (n == 1) { cout << 0 << endl; continue; }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!mp.count(i)) ans += (i == 1 || i == n ? 2 : 3);
            else if (i == 1 || i == n) ans += 1 - mp[i].size();
            else ans += 2 - mp[i].size();
        }
        cout << ans << endl;
    }
    return 0;
}