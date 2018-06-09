#include <bits/stdc++.h>
using namespace std;
int dp[2][2049];
struct node
{
	int type, id1, id2;
	bool f1, f2;
};
node a[5001];
bool same(bool a, bool b)
{
	return (a && b) || (!a && !b);
}
int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof dp);
		cin >> n >> k;
		string s;
		getchar();
		for (int i = 1; i < n; i++)
		{
			getline(cin, s);
			string tmp;
			stringstream ss(s);
			vector<string> v;
			while (ss >> tmp) v.push_back(tmp);
			if (v[2][0] == 'I')
			{
				a[i].type = 2;
				a[i].id1 = atoi(v[4].c_str());
				a[i].id2 = atoi(v[10].c_str());
				a[i].f1 = v[7] == "good" ? true : false;
				a[i].f2 = v[13] == "good" ? true : false;
			}
			else
			{
				a[i].type = 1;
				a[i].id1 = atoi(v[3].c_str());
				a[i].f1 = v[6] == "good" ? true : false;
			}
		}
		
		int msk = (1 << k + 1) - 1;
		dp[0][1] = 1;
		for (int i = 1; i < n; i++)
		{
			memset(dp[i & 1], 0, sizeof dp[i & 1]);
			for (int j = 0; j < 1 << k + 1; j++)
			{
				if (i < k + 1 && j >= 1 << i) continue;
				int tmp = j << 1 & msk;
				dp[i & 1][tmp] = max(dp[i & 1][tmp], dp[i - 1 & 1][j]);
				if (a[i].type == 1)
				{
					int p1 = i - a[i].id1;
					if (same(a[i].f1, j >> p1 & 1))
					{
						dp[i & 1][tmp | 1] = max(dp[i & 1][tmp | 1], dp[i - 1 & 1][j] + 1);
					}
				}
				else
				{
					int p1 = i - a[i].id1, p2 = i - a[i].id2;
					bool g1 = j >> p1 & 1, g2 = j >> p2 & 1;
					if (!(same(a[i].f1, g1) && !same(a[i].f2, g2)))
						dp[i & 1][tmp | 1] = max(dp[i & 1][tmp | 1], dp[i - 1 & 1][j] + 1);
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < 1 << k + 1; i++)
			ans = max(ans, dp[n - 1 & 1][i]);
		cout << ans << endl;
	}
	return 0;
}