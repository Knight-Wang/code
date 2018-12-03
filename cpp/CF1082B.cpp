#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n; string s;
	while (cin >> n)
	{
		cin >> s;
		s += 'S';
		vector<pair<int, int>> v;
		int i = 0;
		while (i <= n && s[i] == 'S') i++;
		int last = i;
		for (int j = i; j <= n; j++)
		{
			if (s[j] == 'G') continue;
			else
			{
				v.push_back(make_pair(last, j - 1));
				while (j <= n && s[j] == 'S') j++;
				last = j;
			}
		}
		if (v.size() == 0) { cout << 0 << endl; continue; }
		int max1 = 0;
		for (auto it: v) max1 = max(max1, it.second - it.first + 1);
		int max2 = 0;
		for (int i = 0; i < v.size() - 1; i++)
		{
			if (v[i].second + 2 == v[i + 1].first)
				max2 = max(max2, v[i].second - v[i].first + v[i + 1].second - v[i + 1].first + 2);
		}
		if (max2 == 0) 
		{
			if (v.size() >= 2) cout << max1 + 1 << endl;
			else cout << max1 << endl;
		}
		else
		{
			if (v.size() >= 3) cout << max(max1 + 1, max2 + 1) << endl;
			else cout << max(max1 + 1, max2) << endl;
		}
	}
	return 0;
}