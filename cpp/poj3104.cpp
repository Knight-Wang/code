#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100005;
int a[MAXN], n, k;
int Ceil(int a, int c)
{
	return (a + c - 1) / c;
}
bool check(int x)
{
	ll tot = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > x) tot += Ceil(a[i] - x, k - 1);
		if (tot > x) return false;
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	int maxn = 0;
	for (int i = 0; i < n; i++) 
	{ 
		scanf("%d", &a[i]); 
		maxn = max(maxn, a[i]); 
	}
	scanf("%d", &k);
	if (k == 1) { printf("%d\n", maxn); return 0; }
	int l = 1, r = maxn, ans = maxn;
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
	return 0;
}