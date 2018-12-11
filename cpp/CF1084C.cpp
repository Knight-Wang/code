#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll dp[100005];
int main()
{
	string s;
	while (cin >> s)
	{
		memset(dp, 0, sizeof dp);
		int n = s.length();
		ll sum = 0;
		int pos = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == 'a')
			{
				dp[i] = (dp[i] + 1 + sum) % MOD;
			}
			else if (s[i] == 'b')
			{
				while (pos < i)
				{
					if (s[pos] == 'a') sum = (sum + dp[pos]) % MOD;
					pos++;
				}
			}
		}
		ll ans = 0;
		for (int i = 0; i < n; i++) ans = (ans + dp[i]) % MOD;
		cout << ans << endl;
	}
	return 0;
}