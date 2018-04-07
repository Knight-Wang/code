#include <iostream>
#include <cstring>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXM = 1005, MAXB = 55;
int dp[MAXM][MAXB];
int main()
{
	int n, x, b, m;
	cin >> n;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 0; i <= 50; i++) dp[0][i] = 0;
	for (int i = 0; i <= 1000; i++) dp[i][1] = i;
	for (int i = 1; i <= 1000; i++)
	{
		for (int k = 2; k <= 50; k++)
		{
			int ans = INF;
			for (int j = 1; j <= i; j++)
			{
				ans = min(ans, max(dp[j - 1][k - 1], dp[i - j][k]) + 1);
			}
			dp[i][k] = ans;
		}
	}
	while (n--)
	{
		cin >> x >> b >> m;
		cout << x << " " << dp[m][b] << endl;
	}
	return 0;
}