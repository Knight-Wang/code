//Solution 1
class Solution 
{
public:
	int dfs(int now, bool ok, bool flag, int dp[][2], int num[])
	{
		if (now == 0) return ok;
		if (!flag && dp[now][ok] != -1)
			return dp[now][ok];
		int res = 0;
		int u = flag ? num[now] : 9;
		for (int i = 0; i <= u; i++)
		{
			res += dfs(now - 1, ok || (i == 9), flag && i == u, dp, num);
		}
		return flag ? res : dp[now][ok] = res;
	}
    int newInteger(int n) 
    {
		long long l = n, r = 5e9, res = n;
		int dp[15][2], num[15]; 
		while (l <= r)
		{
			long long m = (l + r) >> 1;
			memset(dp, -1, sizeof dp);
			memset(num, 0, sizeof num);
			int sum = 0;
			long long tmp = m;
			while (tmp)
			{
				num[++sum] = tmp % 10;
				tmp /= 10;
			}
			int ans = dfs(sum, 0, true, dp, num);
			if (m - ans < n) l = m + 1;
			else 
			{
				r = m - 1;
				if (m - ans == n)
					res = m;
			}
		}
		return res;
    }
};
//Solution 2
class Solution 
{
public:
    int newInteger(int n) 
    {
		int sum = 0, x = 1;
        while (n)
        {
            sum += n % 9 * x;
            n /= 9;
            x *= 10;
        }
        return sum;
    }
};