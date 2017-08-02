class Solution 
{
public:
	
	struct cmp
	{
		bool operator()(const vector<int>& a, const vector<int>& b)
		{
			return a[1] < b[1];
		}
	};
	
    int findLongestChain(vector<vector<int>>& pairs) 
    {
		vector<vector<int>> t(pairs.begin(), pairs.end());
		sort(t.begin(), t.end(), cmp());
		int dp[1005], n = t.size();
		for (int i = 0; i < n; i++) dp[i] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (t[i][0] > t[j][1] && dp[i] + 1 > dp[j])
					dp[j] = dp[i] + 1;
			}
		}
		return dp[0];
    }
};