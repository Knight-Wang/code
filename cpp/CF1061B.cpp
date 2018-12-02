#include <bits/stdc++.h>
using namespace std;
int a[100005];
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		long long ans = 0;
		int maxn = a[1], cnt = a[1] - 1;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] == a[i - 1])
			{
				if (cnt) { ans += a[i]; cnt--; }
				else ans += a[i] - 1;
			}
			else 
			{
				cnt += a[i] - maxn - 1;
				ans += maxn;
				maxn = a[i];
			}
		}
		cout << ans << endl;
	}
	return 0;
}