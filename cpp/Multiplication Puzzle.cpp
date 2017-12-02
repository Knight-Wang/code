#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, a[105], dp[105][105];
int dfs(int l, int r)
{
	if (r == l + 1) return 0;
	if (r == l + 2) return a[l] * a[l + 1] * a[l + 2];
	if (dp[l][r] != -1) return dp[l][r];
	int minn = INF;
	for (int i = l + 1; i <= r - 1; i++)
	{
		minn = min(minn, dfs(l, i) + dfs(i, r) + a[i] * a[l] * a[r]);
	}
	return dp[l][r] = minn;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(dp, -1, sizeof dp);
	cout << dfs(0, n - 1) << endl;
	return 0;
}