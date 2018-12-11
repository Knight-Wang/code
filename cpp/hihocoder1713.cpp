#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 22;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};
int n, m; 
ll dp[(1 << 20) + 5];
char a[MAXN][MAXN], tmp[MAXN][MAXN];
bool check(int x, int y, int S)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < m && (S & (1 << (nx * m + ny))))
			return true;
	}
	return false;
}
ll dfs(int now, int S)
{
	if (dp[S] != -1) return dp[S];
	if (now == n * m) return 1;
	ll cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int x = i * m + j;
			if (!(S & (1 << x)) && check(i, j, S))
				cnt += dfs(now + 1, S | (1 << (i * m + j)));
		}
	}
	return dp[S] = cnt;
}

int main()
{
	cin >> n >> m;
	int now = 0, S = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == '1') 
			{
				now++;
				S |= (1 << i * m + j);
			}
		}
	}	
	memset(dp, -1, sizeof dp);
	cout << dfs(now, S) << endl;
	return 0;
}
