#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[105][5005];
int dfs(int n, int m)
{
    if (m < 0 || m > n * (n - 1) >> 1) return 0;
	if (!m) return 1;
	if (dp[n][m] != -1) return dp[n][m];
	for (int i = 1; i <= n; i++)
	{
		if (dfs(n - i, m - i * (n - i)))
			return dp[n][m] = 1;
	}
	return dp[n][m] = 0;
}

int main()
{
	//freopen("D:\\codes\\tmp\\in.txt", "r", stdin);
	int kase = 1, n, m;
	memset(dp, -1, sizeof(dp));
	while (cin >> n >> m, n + m)
	{
		if (dfs(n, m))
			cout << "Case " << kase++ << ": " << n << " lines with exactly " << m << " crossings can cut the plane into " << n + m + 1 << " pieces at most." << endl;
		else
			cout << "Case " << kase++ << ": " << n << " lines cannot make exactly " << m << " crossings." << endl;
	}
	return 0;
}