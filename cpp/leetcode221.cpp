#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(m, 0);
        int maxn = 0;
        for (int i = 0; i < m; i++)
        {
            dp[i] = matrix[i][0] - '0';
            maxn = max(maxn, dp[i]);
        }
        for (int i = 1; i < n; i++)
        {
			int pre = dp[0];
			dp[0] = matrix[0][i] - '0';
			maxn = max(dp[0], maxn);
            for (int j = 1; j < m; j++)
            {
                if (matrix[j][i] == '1')
                {
                    pre = min(pre, min(dp[j - 1], dp[j])) + 1;
					swap(dp[j], pre);
                    maxn = max(maxn, dp[j]);
                }
                else dp[j] = 0;
            }
        }
        return maxn * maxn;
    }
};
int main()
{
	vector<vector<char>> matrix;
	vector<char>v0 = {'1', '1', '1', '1'};
	matrix.push_back(v0);
	vector<char>v1 = v0;
	matrix.push_back(v1);
	vector<char>v2 = v1;
	matrix.push_back(v2);
	Solution s;
	cout << s.maximalSquare(matrix) << endl;
	return 0;
}