#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll f[100005];
int main()
{
    string s;
    f[1] = 1; f[2] = 2;
    for (int i = 3; i <= 100000; i++) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    while (cin >> s)
    {
        int n = s.length();
        bool flg = true;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'm' || s[i] == 'w') { flg = false; break; }
        }
        if (!flg) { cout << 0 << endl; continue; }
        ll res = 1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != 'u' && s[i] != 'n') continue;
            int j = i;
            while (j + 1 < n && s[j + 1] == s[j]) j++;
            res = res * f[j - i + 1] % MOD;
            i = j;
        }
        cout << res << endl;
    }
    return 0;
}