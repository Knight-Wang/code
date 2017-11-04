#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int findLength(vector<int>& A, vector<int>& B)
	{
		int n = A.size(), m = B.size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1));
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (A[i - 1] == B[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = 0;
				maxn = max(maxn, dp[i][j]);
			}
		}
		return maxn;
	}
};

int main()
{
	vector<int> a = { 1, 2, 4, 4, 5, 6}, b = { 1, 2, 3, 4, 5, 6};
	cout << Solution().findLength(a, b) << endl;
	return 0;
}

