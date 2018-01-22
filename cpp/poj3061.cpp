#include <cstdio>
using namespace std;
const int MAXN = 100005;
int a[MAXN], sum[MAXN], n, m;

bool check(int l)
{
	for (int i = 1; i <= n - l + 1; i++)
	{
		if (sum[i + l - 1] - sum[i - 1] >= m) return true;
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			sum[i] = sum[i - 1] + a[i];
		}
		if (sum[n] < m) { puts("0"); continue; }
		int l = 1, r = n, ans = n;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			if (check(m))
			{
				ans = m; r = m - 1;
			}
			else l = m + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}