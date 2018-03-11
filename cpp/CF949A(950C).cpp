#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int main()
{
	string s;
	while (cin >> s)
	{
		set<int> x, y;
		for (int i = 0; i < v.size(); i++) v[i].clear();
		bool no_ans = false;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '1')
			{
				if (x.empty()) { no_ans = true; break; }
				auto be = x.begin(); 
				int tmp = *be;
				x.erase(be);
				v[tmp].push_back(i);
				y.insert(tmp);
			}
			else
			{
				if (y.empty()) { v.push_back(vector<int>()); y.insert(v.size() - 1); }
				auto be = y.begin(); 
				int tmp = *be;
				y.erase(be);
				v[tmp].push_back(i);
				x.insert(tmp);
			}
		}
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].size() && s[v[i].back()] == '1') no_ans = true;
		}
		if (no_ans) cout << -1 << endl;
		else 
		{
			cout << v.size() << endl;
			for (int i = 0; i < v.size(); i++)
			{
				cout << v[i].size() << " ";
				for (int j = 0; j < v[i].size(); j++)
				{
					cout << v[i][j] + 1 << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}