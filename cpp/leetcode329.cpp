class Solution 
{
public:
	int dfs(const int * dx, const int * dy, vector<vector<int>> & matrix, vector<vector<int>> & dp, int x, int y)
	{
		if (dp[x][y] != -1) return dp[x][y];
		int ans = 1, n = matrix.size(), m = matrix[0].size();
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k], ny = y + dy[k];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nx][ny] < matrix[x][y])
			{
				ans = max(ans, 1 + dfs(dx, dy, matrix, dp, nx, ny));
			}
		}
		return dp[x][y] = ans;
	}
    int longestIncreasingPath(vector<vector<int>>& matrix) 
	{
		int n = matrix.size();
        if (!n) return 0;
        int m = matrix[0].size();
		vector<vector<int>> dp(n, vector<int>(m, -1));
		const int dx[4] = {1, 0, -1, 0};
		const int dy[4] = {0, 1, 0, -1};
		int ans = 1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int tmp = dfs(dx, dy, matrix, dp, i, j);
				ans = max(ans, tmp);
			}
		}
		return ans;
    }
};