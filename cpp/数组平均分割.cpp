#include <bits/stdc++.h>
using namespace std;

int splitToMin(int a[], int n, int b[], int c[])
{
	int sum = accumulate(a, a + n, 0);
	int dp[15][1005];
	memset(dp, 0, sizeof dp);
	for (int i = 1; i <= n; i++)
	{
		for (int j = sum >> 1; j >= a[i - 1]; j--)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + a[i - 1]);
		}
	}
	int tot = dp[n][sum >> 1], ans[15];
	memset(ans, 0, sizeof ans);
	for (int i = n; i >= 1; i--)
	{
		if (dp[i][tot] > dp[i - 1][tot])
		{
			tot -= a[i - 1];
			ans[i - 1] = 1;
		}
	}
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		if (ans[i]) b[x++] = a[i];
		else c[y++] = a[i];
	}
	return abs(sum - 2 * dp[n][sum >> 1]);
}

int main()
{
	int a[] = {61, 82, 100, 61, 61};
	int b[10], c[10];
	memset(b, 0, sizeof b); memset(c, 0, sizeof c);
	cout << splitToMin(a, 5, b, c) << endl;
	for (int i = 0; i < 5; i++) cout << b[i] << " ";
	cout << endl;
	for (int i = 0; i < 5; i++) cout << c[i] << " ";
	cout << endl;
	return 0;
}