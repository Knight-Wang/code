#include <bits/stdc++.h>
using namespace std;
int a[1005], inv[100005], ans[1005], dp[100005], path[100005];
int main()
{
	int k;
	cin >> k;
	if (!k) { cout << "a"; return 0; }
	int i = 1;
	memset(dp, 0x3f, sizeof dp);
	memset(path, 0, sizeof path);
	dp[0] = 0; path[0] = -1;
	for ( ; i * (i - 1) <= 2 * k; i++) 
	{ 
		a[i] = i * (i - 1) >> 1; 
		inv[i * (i - 1) >> 1] = i;
	}
	for (int j = 2; j < i; j++)
	{
		for (int p = a[j]; p <= k; p++)
		{
			if (dp[p - a[j]] + 1 < dp[p])
			{
				dp[p] = dp[p - a[j]] + 1;
				path[p] = p - a[j];
			}
		}
	}
	while (path[k] != -1) { ans[inv[k - path[k]]]++; k = path[k]; }
	char now = 'a';
	for (int j = 2; j < i; j++) 
	{
		if (ans[j]) 
		{ 
			for (int x = 0; x < ans[j]; x++)
			{
				for (int p = 0; p < j; p++) cout << now;
				now++;
			}
		}
	}
	return 0;
}