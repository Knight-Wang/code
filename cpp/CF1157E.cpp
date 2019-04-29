#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    int n, x;
    while (cin >> n)
    {
        map<int, int> mp;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
        for (int i = 1; i <= n; i++)
        {
            auto it = mp.lower_bound(n - a[i]);
            if (it == mp.end()) it = mp.lower_bound(0);
            cout << (a[i] + it->first) % n << " ";
            if (it->second == 1) mp.erase(it);
            else it->second--;
        }
        cout << endl;
    }
    return 0;
}