#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, q;
	string f, s;
	cin >> n;
	map<string, string> mp;
	for (int i = 0; i < n; i++)
	{
		cin >> f >> s;
		mp[s] = f;
	}
	cin >> q;
	string x, y;
	for (int i = 0; i < q; i++)
	{
		cin >> x >> y;
		set<string> st;
		st.insert(x);
		while (mp.count(x))
		{
			st.insert(mp[x]);
			x = mp[x];
		}
		if (st.count(y)) { cout << y << endl; continue; }
		bool flg = false;
		while (mp.count(y))
		{
			if (st.count(mp[y]))
			{
				flg = true; cout << mp[y] << endl; break;
			}
			y = mp[y];
		}
		if (!flg) cout << -1 << endl;
	}
	return 0;
}