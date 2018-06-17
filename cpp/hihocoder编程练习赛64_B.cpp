#include <bits/stdc++.h>
using namespace std;
int a[13], b[13];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		sort(a, a + n); sort(b, b + n);
		if (b[n - 1] < a[n - 1]) { cout << 0 << endl; continue; }
		int ans = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			int pos = lower_bound(b, b + n, a[i]) - b;
			int cnt = n - pos;
			ans *= cnt - (n - 1 - i);
		}
		cout << ans << endl;
	}
	return 0;
}