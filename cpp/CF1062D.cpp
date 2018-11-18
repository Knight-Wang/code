#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while (cin >> n)
	{
		ll cnt = 0;
		for (int i = 2; i * i <= n; i++)
		{
			ll tmp = n / i;
			cnt += (i + 1 + tmp) * (tmp - i) / 2;
			cnt += (tmp - i + 1) * i;
		}
		cout << (cnt << 2) << endl; 
	}
	return 0;
}