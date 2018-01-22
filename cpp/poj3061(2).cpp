#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int a[MAXN];
int main()
{
	int T, n, m;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int s = 0, t = 0, sum = 0, ans = INF;
		while (t < n)
		{
			while (t < n && sum < m) sum += a[t++];
			while (s < t && sum >= m) { ans = min(ans, t - s); sum -= a[s++]; }
		}
		if (ans == INF) puts("0");
		else printf("%d\n", ans);
	}
	return 0;
}