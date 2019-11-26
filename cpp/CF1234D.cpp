#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        int n; cin >> n;
        vector<set<int>> v(26, set<int>());
        for (int i = 0; i < s.length(); i++)
        {
            v[s[i] - 'a'].insert(i);
        }
        while (n--)
        {
            int t, p, l, r; char x; cin >> t;
            if (t == 1)
            {
                cin >> p >> x; p--;
                v[s[p] - 'a'].erase(p);
                v[x - 'a'].insert(p);
                s[p] = x;
            }
            else
            {
                cin >> l >> r; l--; r--;
                int res = 0;
                for (int i = 0; i < 26; i++)
                {
                    auto ans = v[i].lower_bound(l);
                    if (ans != v[i].end() && *ans <= r) res++;
                }
                cout << res << endl;
            }
        }
    }
    return 0;
}