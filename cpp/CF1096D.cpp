#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll a[100005], dp[100005][5];

int main()
{
	int n; string s;
	map<char, int> mp;
	mp['h'] = 1; mp['a'] = 2; mp['r'] = 3; mp['d'] = 4;
	while (cin >> n >> s)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		dp[0][0] = INF;
		for (int i = 1; i <= 4; i++) dp[0][i] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= 4; j++) dp[i][j] = dp[i - 1][j];
			if (mp.count(s[i - 1]))
			{
				int tmp = mp[s[i - 1]];
				dp[i][tmp] = min(dp[i - 1][tmp - 1], dp[i - 1][tmp] + a[i - 1]);
			}
		}
		ll ans = INF;
		for (int i = 0; i <= 4; i++) ans = min(ans, dp[n][i]);
		cout << ans << endl;
	}
	return 0;
}