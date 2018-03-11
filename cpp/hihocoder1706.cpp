#pragma comment(linker, "/STACK:1024000000, 1024000000") 
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
int n, m, x;
vector<pii> v;
int dp[101][101][500];
int dfs(int now, int s, int d)
{
	if (dp[now][s][d + 250] != -1) return dp[now][s][d + 250];
	if (now == n) return s == m ? 0 : -INF;
	int ans = dfs(now + 1, s, d);
	int c2 = v[now].first, c5 = v[now].second;
	int x = 0;
	if (d > 0 && (c2 - c5) > 0)
		x = min(d, c2 - c5);
	else if (d < 0 && (c2 - c5) < 0)
		x = -max(d, (c2 - c5));
	int tmp = min(c2, c5) + dfs(now + 1, s + 1, d - (c2 - c5)) + x;
	return dp[now][s][d + 250] = max(ans, tmp);
}

int main()
{
	cin >> n >> m;
	memset(dp, -1, sizeof dp);
	for (int i = 1; i <= n; i++) 
	{
		cin >> x;
		int c2 = 0, c5 = 0;
		while (x && x % 2 == 0) { c2++; x /= 2; }
		while (x && x % 5 == 0) { c5++; x /= 5; }
		v.push_back(pii(c2, c5));
	}
	cout << dfs(0, 0, 0) << endl;
	return 0;
}