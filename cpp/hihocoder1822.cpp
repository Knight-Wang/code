#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int buf[6], need[6][10005];

int main()
{
	int T, n, m;
	cin >> T;
	map<string, int> mp;
	mp["CV"] = 0; mp["DD"] = 1; mp["CL"] = 2;
	mp["CA"] = 3; mp["BB"] = 4; mp["BC"] = 5;
	while (T--)
	{
		memset(need, 0, sizeof need);
		cin >> n >> m;
		string s;
		int l, f;
		vector<pii> v[6];
		for (int i = 0; i < n; i++)
		{
			cin >> s >> l >> f;
			v[mp[s]].push_back(pii(l, f));
		}
		for (int i = 0; i < 6; i++) sort(v[i].begin(), v[i].end());
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < 6; j++) cin >> buf[j];
			cin >> l;
			for (int j = 0; j < 6; j++)
			{
				need[j][l] += buf[j];
			}
		}
		bool flg = true;
		int ans = 0;
		for (int i = 0; i < 6; i++)
		{
			priority_queue<int, vector<int>, greater<int>> q;
			for (int j = 10000; j >= 1; j--)
			{
				if (need[i][j])
				{
					while (!v[i].empty() && v[i].back().first >= j)
					{	
						q.push(v[i].back().second);
						v[i].pop_back();
					}
					if (q.size() < need[i][j]) { flg = false; break; }
					while (need[i][j]) { ans += q.top(); q.pop(); need[i][j]--; }
				}				
			}
			if (!flg) break;
		}
		if (!flg) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}
