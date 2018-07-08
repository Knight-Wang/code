#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main()
{
	ll n, P;
	while (cin >> n >> P)
	{
		if (n > P - 1) { cout << 0 << endl; continue; }
		ll ans = 1;
		for (ll i = P - 1; i > P - 1 - n; i--)
		{
			ans = ans * i % MOD;
		}
		cout << ans << endl;
	}
	return 0;
}