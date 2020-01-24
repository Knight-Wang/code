#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m, cnt = 0; cin >> n; m = n;
        map<int, int> mp;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0) { mp[i]++; n /= i; cnt++; }
        }
        if (n != 1) { mp[n] = 1; cnt++; }
        vector<pair<int, int>> v;
        for (auto it: mp) v.push_back(make_pair(it.first, it.second));
        if (mp.size() >= 3)
        {
            cout << "YES" << endl;
            cout << v[0].first << " " << v[1].first << " " << m / v[0].first / v[1].first << endl;
        }
        else if (mp.size() == 1)
        {
            if (v[0].second >= 6)
            {
                cout << "YES" << endl;
                cout << v[0].first << " " << v[0].first * v[0].first << " " << m / v[0].first / v[0].first / v[0].first << endl;
            }
            else cout << "NO" << endl;
        }
        else
        {
            if (cnt >= 4)
            {
                cout << "YES" << endl;
                cout << v[0].first << " " << v[1].first << " " << m / v[0].first / v[1].first << endl;
            }
            else cout << "NO" << endl;
        }
    }
    return 0;
}