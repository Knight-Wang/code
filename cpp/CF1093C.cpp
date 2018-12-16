#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a[200005], b[100005];
int n;

bool check(ll x, int pos)
{
	return b[pos] - x <= a[n - pos + 2];
}

int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n / 2; i++) cin >> b[i];
		a[1] = 0; a[n] = b[1];
		for (int i = 2; i <= n / 2; i++)
		{
			ll l = a[i - 1], r = b[i], ans = -1;
			while (l <= r)
			{
				ll m = l + r >> 1;
				if (check(m, i))
				{
					ans = m; r = m - 1;
				}
				else l = m + 1;
			}
			a[i] = ans; a[n - i + 1] = b[i] - a[i];
		}
		for (int i = 1; i <= n; i++) cout << a[i] << " ";
		cout << endl;
	}
	return 0;
}