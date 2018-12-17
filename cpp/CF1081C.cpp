#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 998244353;

ll C[2005][2005];

void init()
{
	memset(C, 0, sizeof C);
	C[0][0] = C[1][0] = C[1][1] = 1;
	for (int i = 2; i <= 2000; i++)
	{
		C[i][0] = 1;
		for (int j = 1; j <= 2000; j++)
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % MOD;
	}
}

int main()
{
	int n, m, k;
	init();
	while (cin >> n >> m >> k)
	{
		ll ans = C[n - 1][k];
		ans = ans * m % MOD;
		for (int i = 0; i < k; i++) ans = ans * (m - 1) % MOD;
		cout << ans << endl;
	}
	return 0;
}