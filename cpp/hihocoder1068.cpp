#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int a[N], st[N][20];
int log2(int x)
{
	int res = -1;
	while (x)
	{
		x >>= 1;
		res++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	int n, q, l, r;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) st[i][0] = a[i];
	for (int j = 1; (1 << j) < n; j++)
	{
		for (int i = 0; i + (1 << j) - 1 < n; i++)
		{
			st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
		}
	}
	cin >> q;
	while (q--)
	{
		cin >> l >> r;
		l--; r--;
		int p = log2(r - l + 1);
		cout << min(st[l][p], st[r - (1 << p) + 1][p]) << endl;
	}
	return 0;
}