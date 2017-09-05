#include <bits/stdc++.h>
using namespace std;
int y[1005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++)
			cin >> y[i];
		bool flg = false;
		int i = 3;
		for (; i <= n; i++)
		{
			if ((y[i] - y[2]) != (2 - i) * (y[2] - y[3]))
				break;
		}
		if ((i == n + 1) && (y[3] - y[2] != y[2] - y[1])) 
			{ puts("Yes"); continue; }
		for (int i = 2; i <= n; i++)
		{
			vector<pair<int, int>> v;
			for (int j = 2; j <= n; j++)
			{
				if (j == i) continue;
				if ((1 - j) * (y[i] - y[j]) != (i - j) * (y[1] - y[j]))
					v.push_back(pair<int, int>(j, y[j]));
			}
			if (v.empty()) continue;
			if (v.size() == 1) { flg = true; break; }
			int j = 2;
			for (; j < (int)v.size(); j++)
			{
				if ((v[0].first - v[j].first) * (v[0].second - v[1].second) != 
					(v[0].first - v[1].first) * (v[0].second - v[j].second))
					break;
			}
			if (j == (int)v.size() && ((1 - i) * (v[0].second - v[1]. second) == (v[0].first - v[1].first) * (y[1] - y[i]))) 
				{ flg = true; break; }	
		}
		if (!flg) puts("No");
		else puts("Yes");
	}
	return 0;
}