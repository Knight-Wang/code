#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int a[105];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		a[n + 1] = INF;
		int last = 1;
		vector<pair<int, int>> v; 
		for (int i = 2; i <= n + 1; i++)
		{
			if (a[i] - a[i - 1] > 1)
			{
				v.push_back(make_pair(last, i - 1));
				last = i;
			}
		}
		int maxn = 0;
		for (auto it: v)
		{
			if (it.first == 1 && it.second == a[it.second])
				maxn = max(maxn, it.second - 1);
			else if (it.second == n && n - it.first == 1000 - a[it.first])
				maxn = max(maxn, it.second - it.first);
			else if (it.second - it.first - 1 > 0) maxn = max(maxn, it.second - it.first - 1);
		}
		cout << maxn << endl;
	}
	return 0;
}