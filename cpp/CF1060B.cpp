#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum(ll x)
{
	string tmp = to_string(x);
	ll ans = 0;
	for (int i = 0; i < tmp.length(); i++)
	{
		ans += tmp[i] - '0';
	}
	return ans;
}
int main()
{
	ll n;
	while (cin >> n)
	{
		ll ans = 0;
		ll x = 9;
		while (x <= n)
		{
			x = x * 10 + 9;
		}
		cout << sum(x / 10) + sum(n - x / 10) << endl;
	}
	return 0;
}
