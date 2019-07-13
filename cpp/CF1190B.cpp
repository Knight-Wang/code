#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        map<ll, int> mp;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (!mp.count(a[i])) mp[a[i]] = 0;
            mp[a[i]]++;
        }
        bool flg = true; int cnt = 0; ll t = -1;
        for (auto it: mp)
        {
            if (it.first == 0 && it.second >= 2) { flg = false; break; }
            else if (it.first > 0)
            {
                if (it.second >= 3) { flg = false; break; }
                else if (it.second == 2) { cnt++; t = it.first; }
            }
        }
        if (cnt >= 2) flg = false;
        if (!flg) { cout << "cslnb" << endl; continue; }
        ll sum = accumulate(a + 1, a + n + 1, 0);
        sum -= (ll)n * (n - 1) / 2;
        if (cnt == 1 && mp.count(t - 1)) cout << "cslnb" << endl;
        else cout << (sum & 1 ? "sjfnb" : "cslnb") << endl;
    }
    return 0;
}