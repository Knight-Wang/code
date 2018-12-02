#include <bits/stdc++.h>
using namespace std;
int a[100005], dp[100005][6];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		memset(dp, 0, sizeof dp);
		for (int i = 1; i <= 5; i++) dp[1][i] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; j <= 5; j++)
			{
				if (a[i] > a[i - 1])
				{
					for (int k = 1; k < j; k++)
					{
						if (dp[i - 1][k]) dp[i][j] = k;
					}
				}
				else if (a[i] < a[i - 1])
				{
					for (int k = j + 1; k <= 5; k++)
					{
						if (dp[i - 1][k]) dp[i][j] = k;
					}
				}
				else
				{
					for (int k = 1; k <= 5; k++)
					{
						if (k != j && dp[i - 1][k]) dp[i][j] = k;
					}
				}
			}
		}
		bool flg = false;
		int i = 1;
		for ( ; i <= 5; i++)
		{
			if (dp[n][i]) { flg = true; break; }
		}
		if (!flg) cout << "-1" << endl;
		else
		{
			vector<int> v;
			v.push_back(i);
			int now = n;
			while (now >= 2)
			{
				v.push_back(dp[now][i]);
				i = dp[now][i];
				now--;
			}
			for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";
			cout << endl;
		}
	}
	return 0;
}