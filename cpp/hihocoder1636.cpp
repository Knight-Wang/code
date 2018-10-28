#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 105;

int a[N], sum[N], dp[N][N][N];
int n, L, R;

int dfs(int l, int r, int k)
{
	if (l == r) return k == 1 ? 0 : INF;
	if (r - l + 1 == k) return 0;
	if (dp[l][r][k] != -1) return dp[l][r][k];
	int ans = INF;
	if (k == 1)
	{
		for (int i = L; i <= R; i++)
			ans = min(ans, dfs(l, r, i) + sum[r] - sum[l - 1]);
	}
	else
	{
		for (int i = 0; i < r - l; i++)
			ans = min(ans, dfs(l, l + i, 1) + dfs(l + i + 1, r, k - 1));
	}
	return dp[l][r][k] = ans;
}

int main()
{
	while (cin >> n >> L >> R)
	{
		memset(sum, 0, sizeof sum);
		memset(dp, -1, sizeof dp);
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			sum[i] = sum[i - 1] + a[i];
		}
		int ans = dfs(1, n, 1);
		cout << (ans == INF ? 0 : ans) << endl;
	}
	return 0;
}
