#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, q;
    while (cin >> n >> q)
    {
        int maxn = -1, x;
        list<int> l;
        for (int i = 1; i <= n; i++)
        {
            cin >> x; l.push_back(x); maxn = max(maxn, x);
        }
        vector<pair<int, int>> v1, v2;
        while (l.front() != maxn)
        {
            int a = l.front(); l.pop_front();
            int b = l.front(); l.pop_front();
            v1.push_back(make_pair(a, b));
            if (a > b) { l.push_front(a); l.push_back(b); }
            else { l.push_front(b); l.push_back(a); }
        }
        l.pop_front();
        for (auto it = l.begin(); it != l.end(); it++) v2.push_back(make_pair(maxn, *it));
        ll t;
        for (int i = 0; i < q; i++)
        {
            cin >> t;
            if (t <= v1.size()) cout << v1[t - 1].first << " " << v1[t - 1].second << endl;
            else
            {
                ll p = (t - v1.size()) % v2.size();
                if (p == 0) p = v2.size();
                cout << v2[p - 1].first << " " << v2[p - 1].second << endl;
            }
        }
    }
    return 0;
}