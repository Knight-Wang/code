#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	vector<int> preprocess(int x)
	{
		vector<int> res;
		while (x) { res.push_back(x % 10); x /= 10; }
		return res;
	}
	int dfs(vector<int>& a, int p, int cnt, bool u, vector<vector<int>>& dp)
	{
		if (p == -1) return cnt;
		if (!u && dp[p][cnt] != -1) return dp[p][cnt];
		int res = 0;
		int h = u ? a[p] : 9;
		for (int i = 0; i <= h; i++)
		{
			res += dfs(a, p - 1, cnt + (i == 1), u && (i == h), dp);
		}
		return u ? res : dp[p][cnt] = res;
	}
    int NumberOf1Between1AndN_Solution(int n)
    {
    	vector<int> a = preprocess(n);
    	int l = a.size();
    	vector<vector<int>> dp(l, vector<int>(l + 1, -1));
    	return dfs(a, l - 1, 0, true, dp);
    }
};

int main()
{
    int n;
    while (cin >> n)
    {
	    cout << Solution().NumberOf1Between1AndN_Solution(n) << endl;
    }
	return 0;
}