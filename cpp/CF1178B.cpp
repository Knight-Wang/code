#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[4];
int main()
{
    string s;
    while (cin >> s)
    {
        memset(dp, 0, sizeof dp);
        string t = "";
        int n = s.length();
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'v' && s[i + 1] == 'v') t += 'w';
            else if (s[i] == 'o') t += 'o';
        }
        n = t.length();
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (t[i - 1] == 'w') { dp[1] += dp[0]; dp[3] += dp[2]; }
            else dp[2] += dp[1];
        }
        cout << dp[3] << endl;
    }
    return 0;
}