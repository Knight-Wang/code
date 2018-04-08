#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int bit[MAXN], a[MAXN], d1[MAXN], d2[MAXN], n;
int lowbit(int x) { return x & -x; }
void update(int i, int x)
{
	while (i <= MAXN) { bit[i] = max(x, bit[i]); i += lowbit(i); }
}
int query(int i)
{
	int ans = 0;
	while (i) { ans = max(ans, bit[i]); i -= lowbit(i); }
	return ans;
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int tmp = 100001 - a[i];
		d1[i] = query(tmp - 1) + 1;
		update(tmp, d1[i]);
	}
	memset(bit, 0, sizeof bit);
	for (int i = n; i >= 1; i--)
	{
		d2[i] = query(a[i] - 1) + 1;
		update(a[i], d2[i]);
	}
	for (int i = 1; i <= n; i++) d1[i] = max(d1[i], d1[i - 1]);
	for (int i = n; i >= 1; i--) d2[i] = max(d2[i], d2[i + 1]);
	int maxn = 2;
	for (int i = 1; i <= n; i++) maxn = max(maxn, d1[i] + d2[i + 1]);
	cout << maxn << endl;
	return 0;
}