#include <bits/stdc++.h>
using namespace std;
bool check(map<int, int>& mp)
{
    if (mp.size() == 1) return true;
    vector<int> v;
    for (auto it: mp) v.push_back(it.second);
    sort(v.begin(), v.end());
    int m = v.size();
    if (v[m - 1] == v[m - 2] + 1)
    {
        for (int i = 0; i < m - 2; i++)
        {
            if (v[i] != v[i + 1]) return false;
        }
        return true;
    }
    else if (v[0] == 1)
    {
        for (int i = 1; i < m - 1; i++)
        {
            if (v[i] != v[i + 1]) return false;
        }
        return true;
    }
    return false;
}
int main()
{
    int n, x;
    while (cin >> n)
    {
        map<int, int> mp;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++; 
            if (check(mp)) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}