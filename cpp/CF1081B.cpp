#include <bits/stdc++.h>
using namespace std;
vector<int> v[100005];
int ans[100005];
int main()
{
	int n, x;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) { v[i].clear(); ans[i] = 0; }
		for (int i = 1; i <= n; i++)
		{
			cin >> x; x = n - x; v[x].push_back(i);
		}
		bool flg = true;
		for (int i = 1; i <= n; i++)
		{
			if (v[i].size() % i != 0) { flg = false; break; }
		}
		if (!flg) { cout << "Impossible" << endl; continue; }
		cout << "Possible" << endl;
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < v[i].size(); j++)
			{
				if (j % i == 0) cnt++;
				ans[v[i][j]] = cnt;
			}
		}
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
		cout << endl;
	}
	return 0;
}