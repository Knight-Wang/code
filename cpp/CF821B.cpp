#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll m, b;
int main()
{
	cin >> m >> b;
	ll maxn = 0;
	for (ll i = 0; i <= m * b; i++)
	{
		ll j = - i / m + b;
		if (m * j + i - m * b <= 0)
		{
			ll ans = (i + 1) * (j + 1) * (i + j) / 2;
			if (ans > maxn) 
				maxn = ans;
		}
	}
	cout << maxn << endl;
	return 0;
}