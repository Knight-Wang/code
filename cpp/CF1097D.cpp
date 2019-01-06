#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll dp[10005][60];

ll qpow(ll x, ll n)
{
    ll res = 1;
    while (n)
    {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

ll inv(ll x)
{
    return qpow(x, MOD - 2);
}

map<ll, int> fac(ll x)
{
	map<ll, int> ans;
	for (ll i = 2; i * i <= x; i++)
	{
		while (x % i == 0)
		{
			x /= i;
			ans[i]++;
		}
	}
	if (x != 1) ans[x] = 1;
	return ans;
}

int main()
{
	ll n; int k;
	while (cin >> n >> k)
	{
		map<ll, int> ans = fac(n);
		ll res = 1;
		for (auto it: ans)
		{
			memset(dp, 0, sizeof dp);
			ll tmp = it.first; int cnt = it.second;
			dp[0][cnt] = 1;
			for (int i = 1; i <= k; i++)
			{
				dp[i][cnt] = dp[i - 1][cnt] * inv(cnt + 1) % MOD;
				for (int j = cnt - 1; j >= 0; j--)
				{
					dp[i][j] = dp[i][j + 1];
					dp[i][j] = (dp[i][j] + dp[i - 1][j] * inv(j + 1)) % MOD;
				}
			}
			ll sum = 0;
			for (int i = 0; i <= cnt; i++)
			{
				sum = (sum + dp[k][i] * qpow(tmp, i) % MOD) % MOD;
			}
			res = res * sum % MOD;
		}
		cout << res << endl;
	}
	return 0;
}