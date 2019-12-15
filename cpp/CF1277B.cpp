#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            int cnt = 0;
            while (x % 2 != 1) { x /= 2; cnt++; }
            if (mp.count(x)) mp[x] = max(mp[x], cnt);
            else mp[x] = cnt;
        }
        int res = 0;
        for (auto it: mp) res += it.second;
        cout << res << endl;
    }
    return 0;
}