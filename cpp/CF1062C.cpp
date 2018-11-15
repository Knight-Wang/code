#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
ll a[1000005], b[1000005];
int main()
{
	int n, q;
	string s;
	while (cin >> n >> q)
	{
		cin >> s;
		int l, r;
		for (int i = 1; i <= n; i++)
		{
			a[i] = s[i - 1] - '0';
			a[i] = a[i - 1] + a[i];
		}
		b[0] = 1;
		for (int i = 1; i <= 1000000; i++)
		{
			b[i] = b[i - 1] * 2 % MOD;
		}
		while (q--)
		{
			cin >> l >> r;
			int len = r - l + 1, x = a[r] - a[l - 1];
			cout << (b[len] - b[len - x] + MOD) % MOD << endl;
		}
	}
	return 0;
}