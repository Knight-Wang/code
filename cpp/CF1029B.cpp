#include <bits/stdc++.h>
using namespace std;
int a[200005], dp[200005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		dp[n - 1] = 1;
		int maxn = 1;
		for (int i = n - 2; i >= 0; i--)
		{
			if (a[i] * 2 >= a[i + 1]) dp[i] = dp[i + 1] + 1;
			else dp[i] = 1;
			maxn = max(maxn, dp[i]);
		}
		cout << maxn << endl;
	}
	return 0;
}