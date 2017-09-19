#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
bool check(int x, unordered_map<int, int>& m)
{
	for (auto it : m)
	{
		int a = it.first, b = it.second;
		if ((a + x - 1) / x != b) return false;
	}
	return true;
}
int main()
{
	while (cin >> n >> m)
	{
		unordered_map<int, int> mp;
		for (int i = 0; i < m; i++)
		{
			cin >> x >> y;
			mp[x] = y;
		}
		int ans = -1;
		bool flg = true;
		for (int i = 1; i <= 100; i++)
		{
			if (check(i, mp))
			{
				if (ans != -1 && (n + i - 1) / i != ans)
				{
					flg = false; break;
				}
				else ans = (n + i - 1) / i;
			}
		}
		if (flg && ans != -1) cout << ans << endl;
		else cout << -1 << endl;
	}
	return 0;
}