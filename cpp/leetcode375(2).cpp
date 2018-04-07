#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	int dfs(int l, int r, vector<vector<int>> & dp)
	{
		if (l == r) return 0;
		if (dp[l][r] != -1) return dp[l][r];
		int ans = 0x3f3f3f3f;
		ans = min(ans, l + dfs(l + 1, r, dp));
		ans = min(ans, r + dfs(l, r - 1, dp));
		for (int i = l + 1; i <= r - 1; i++)
		{
			ans = min(ans, max(dfs(l, i - 1, dp), dfs(i + 1, r, dp)) + i);
		}
		return dp[l][r] = ans;
	}
    int getMoneyAmount(int n) 
	{
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
		return dfs(1, n, dp);
    }
};
int main()
{
	cout << Solution().getMoneyAmount(2) << endl;
	return 0;
}