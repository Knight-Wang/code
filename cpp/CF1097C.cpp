#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; string s;
	while (cin >> n)
	{
		map<int, int> mp;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			int l = 0, r = 0;
			for (int j = 0; j < s.length(); j++)
			{
				if (s[j] == '(') l++;
				else if (l > 0) l--;
				else r++; 
			}
			if (l > 0 && r > 0) continue;
			if (l > 0) mp[-l]++;
			else mp[r]++;
		}
		int ans = 0;
		for (auto it: mp)
		{
			if (it.first > 0)
			{
				int tmp = -it.first;
				if (mp.count(tmp))
				{
					int t = it.second;
					int r = mp[tmp];
					ans += min(t, r);
				}
			}
			else if (it.first == 0)
			{
				int tmp = mp[0];
				ans += tmp / 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}