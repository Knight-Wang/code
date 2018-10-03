#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 1000005;
ll a[MAXN * 2], q[MAXN * 2], minn[MAXN], sum[MAXN * 2];
int main()
{
	ios::sync_with_stdio(false);
	int T, n;
	ll c;
	cin >> T;
	while (T--)
	{
		memset(q, 0, sizeof q);
		memset(minn, 0, sizeof minn);
		memset(sum, 0, sizeof sum);
		cin >> n >> c;
		ll x;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			a[i] -= x;
			a[i + n] = a[i];
		}
		for (int i = 1; i <= 2 * n - 1; i++) sum[i] = sum[i - 1] + a[i];
		int front = 1, back = 1;
		q[front] = 1;
		for (int i = 1; i <= 2 * n - 1; i++)
		{
			while (sum[i] <= sum[q[back]] && back >= front)
				back--;
			q[++back] = i;
			while (q[front] <= i - n && front < back)
				front++;
			if (i >= n) minn[i - n + 1] = sum[q[front]];
		}
		int i = 1;
		for ( ; i <= n; i++)
		{
			if (minn[i] >= sum[i - 1] - c) break;
		}
		cout << (i == n + 1 ? -1 : i) << endl;
	}
	return 0;
}