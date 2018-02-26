#include <bits/stdc++.h>
using namespace std;
int dp[5];
int main()
{
	int n, d;
	while (cin >> n)
	{	
		memset(dp, 0, sizeof dp);
		for (int i = 0; i < n; i++)
		{	
			cin >> d;
			if (d == 1) 
			{
				dp[1]++;
				dp[3] = max(dp[2], dp[3]) + 1;
			}
			else 
			{
				dp[2] = max(dp[1], dp[2]) + 1;
				dp[4] = max(dp[3], dp[4]) + 1;
			}
		}
		int ans = -1;
		for (int i = 1; i <= 4; i++) ans = max(ans, dp[i]);
		cout << ans << endl;
	}
	return 0;
}