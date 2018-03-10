#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	const int MOD = 1e9 + 7;
	int numTilings(int N)
	{
		vector<vector<int>> dp(N + 1, vector<int>(3, 0));
		dp[0][0] = 1;
		dp[1][0] = dp[1][1] = dp[1][2] = 1;
		for (int i = 2; i <= N; i++)
		{
			dp[i][0] = (((dp[i - 1][0] + dp[i - 2][1]) % MOD + dp[i - 2][2]) % MOD + dp[i - 2][0]) % MOD;
			dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
			dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
		}
		return dp[N][0] % MOD;
	}	
};
int main()
{
	cout << Solution().numTilings(30) << endl;
	return 0;
}