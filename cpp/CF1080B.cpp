#include <bits/stdc++.h>
using namespace std;
int main()
{
	int q, l, r;
	long long a, b, ans = 0;
	cin >> q;
	while (q--)
	{
		ans = 0;
		cin >> l >> r;
		if (l & 1) a = l;
		else a = l + 1;
		if (r & 1) b = r;
		else b = r - 1;
		if (a <= b) ans -= (a + b) * ((b - a) / 2 + 1) / 2;
		if (l & 1) a = l + 1;
		else a = l;
		if (r & 1) b = r - 1;
		else b = r;
		if (a <= b) ans += (a + b) * ((b - a) / 2 + 1) / 2;
		cout << ans << endl;
	}
	return 0;
}