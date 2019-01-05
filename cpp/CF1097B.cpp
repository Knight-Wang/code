#include <bits/stdc++.h>
using namespace std;

int a[20], n;

bool dfs(int now, int sum)
{
	if (now == n) return sum % 360 == 0;
	return dfs(now + 1, sum + a[now]) || dfs(now + 1, sum - a[now]);
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		if (dfs(0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}