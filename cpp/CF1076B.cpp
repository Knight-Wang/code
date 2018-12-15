#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	ll n;
	while (cin >> n)
	{
		if (n % 2 == 0) cout << n / 2 << endl;
		else
		{
			bool flg = false;
			ll i = 2;
			for ( ; i * i <= n; i++)
			{
				if (n % i == 0)
				{
					flg = true;
					break;
				}
			}
			if (!flg) cout << 1 << endl;
			else cout << (n - i) / 2 + 1 << endl;
		}
	}
	return 0;
}