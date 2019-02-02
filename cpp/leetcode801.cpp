#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwap(vector<int>& A, vector<int>& B)
    {
    	int n = A.size();
    	vector<vector<int>> dp(n, vector<int>(2, 0x3f3f3f3f));
    	dp[0][0] = 0, dp[0][1] = 1;
    	for (int i = 1; i < n; i++)
    	{
    		if (A[i] > A[i - 1] && B[i] > B[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][0]);
    		if (A[i] > B[i - 1] && B[i] > A[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][0] + 1);
    		if (A[i] > B[i - 1] && B[i] > A[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
    		if (A[i] > A[i - 1] && B[i] > B[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + 1);
    	}
    	return min(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main()
{
	int a[] = {0, 3, 5, 8, 9}, b[] = {2, 1, 4, 6, 9};
	vector<int> A(a, a + 5), B(b, b + 5);
	cout << Solution().minSwap(A, B) << endl;
	return 0;
}