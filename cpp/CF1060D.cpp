#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int l[100005], r[100005], n;
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			cin >> l[i] >> r[i];
		}
		sort(l, l + n); sort(r, r + n);
		ll ans = 0;
		for (int i = 0; i < n; i++) ans += max(l[i], r[i]);
		cout << ans + n << endl;
	}
	return 0;
}