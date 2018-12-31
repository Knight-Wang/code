#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll n;
	while (cin >> n)
	{
		vector<ll> v;
		for (ll i = 1; i * i <= n; i++)
		{
			if (n % i == 0)
			{
				ll tmp = n / i;
				v.push_back((2 + (tmp - 1) * i) * tmp / 2);
				if (tmp != i)
				{
					v.push_back((2 + (i - 1) * tmp) * i / 2);
				}
			}
		}
		sort(v.begin(), v.end());
		for (auto it: v) cout << it << " ";
		cout << endl;
	}
	return 0;
}
