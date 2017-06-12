#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 5005;
int n, a[MAXN], l[MAXN], r[MAXN], vis[MAXN], dp[MAXN];

int main()
{
	//freopen("c:\\Users\\Host\\Desktop\\in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		if (!l[a[i]]) l[a[i]] = i;
		r[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = dp[i - 1];
		int cur = 0;
		memset(vis, 0, sizeof(vis));
		int minL = l[a[i]]; 
		for (int j = i; j >= 1; j--)
		{
			if (r[a[j]] > i) break;
			if (!vis[a[j]]) vis[a[j]] = 1, cur ^= a[j];	
			minL = min(minL, l[a[j]]);
			if (minL >= j) dp[i] = max(dp[i], dp[j - 1] + cur);
		}	
	}		
	cout << dp[n] << endl;
	return 0;	
} 

