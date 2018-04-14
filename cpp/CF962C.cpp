#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[10];
bool check(int x)
{
	int y = sqrt(x);
	return (y * y == x || (y + 1) * (y + 1) == x) && x;
}
int dfs(int now, int cur, int n)
{
	if (now == n) return check(cur) ? 0 : INF;
	if (cur == 0 && a[now] == 0) return dfs(now + 1, cur, n) + 1;
	return min(dfs(now + 1, cur * 10 + a[now], n), dfs(now + 1, cur, n) + 1);
}
int main()
{
	int x, i;
	while (cin >> x)
	{
		i = 0;
		while (x) { a[i++] = x % 10; x /= 10; }
		for (int j = 0; j < i >> 1; j++) swap(a[j], a[i - 1 - j]);
		int ans = dfs(0, 0, i);
		cout << (ans == INF ? -1 : ans) << endl;
	}
	return 0;
}