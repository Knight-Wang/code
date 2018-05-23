#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500005;
int n, k, d, a[MAXN], bit[MAXN];
inline int lowbit(int x) { return x & -x; }
void add(int i, int x)
{
	while (i <= n) { bit[i] += x; i += lowbit(i); }
}
int sum(int i)
{
	if (i < 0) return -1;
	if (!i) return 1;
	int ans = 0;
	while (i) { ans += bit[i]; i -= lowbit(i); }
	return ans + 1;
}
int main()
{
	while (cin >> n >> k >> d)
	{
		memset(bit, 0, sizeof bit);
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++)
		{
			int pos = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
			if (i - pos + 1 < k) continue;
			if (sum(i - k) - sum(pos - 2) >= 1) add(i, 1);
		}
		cout << (sum(n) - sum(n - 1) ? "YES" : "NO") << endl;
	}
	return 0;
}