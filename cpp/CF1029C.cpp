#include <bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
const int INF = 0x3f3f3f3f;
int a[MAXN], b[MAXN], l1[MAXN], r1[MAXN], l2[MAXN], r2[MAXN];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i] >> b[i];
		l1[0] = -INF; r1[0] = INF; l2[n + 1] = -INF; r2[n + 1] = INF;
		for (int i = 1; i <= n; i++)
		{
			l1[i] = max(l1[i - 1], a[i]);
			r1[i] = min(r1[i - 1], b[i]);
		}
		for (int i = n; i >= 1; i--)
		{
			l2[i] = max(l2[i + 1], a[i]);
			r2[i] = min(r2[i + 1], b[i]);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			int x = max(l1[i - 1], l2[i + 1]);
			int y = min(r1[i - 1], r2[i + 1]);
			ans = max(ans, y - x);
		}
		cout << ans << endl;
	}
	return 0;
}