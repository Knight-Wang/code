#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    while (cin >> s)
    {
        int n = s.length();
        vector<ll> v(26, 0);
        for (int i = 0; i < n; i++) v[s[i] - 'a']++;
        ll ans = *max_element(v.begin(), v.end());
        for (int i = 0; i < 26; i++)
        {
            char a = char('a' + i);
            for (int j = 0; j < 26; j++)
            {
                char b = char('a' + j);
                ll res = 0, c = 0;
                for (int k = 0; k < n; k++)
                {
                    if (s[k] == b) res += c;
                    if (s[k] == a) c++;
                }
                ans = max(ans, res);
            }
        }
        cout << ans << endl;
    }
    return 0;
}