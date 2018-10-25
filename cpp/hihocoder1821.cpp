#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;
int a[100005], n;
ll dp[100005];

ll dfs(int cur)
{
	if (cur >= n) return 0;
	if (dp[cur] != -1) return dp[cur];
	ll sum = 0, ans = -INF;
	for (int i = 0; i < 3; i++)
	{
		sum += a[cur + i];
		ll minn = INF;
		for (int j = 0; j < 3; j++)
		{
			minn = min(minn, dfs(cur + i + 1 + j + 1));
		}
		ans = max(ans, sum + minn);
	}
	return dp[cur] = ans;
}

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	while (cin >> n)
	{
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n, cmp);
		cout << dfs(0) << endl;
	}
	return 0;
}
