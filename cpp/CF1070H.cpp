#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
	int n, q;
	string s;
	while (cin >> n)
	{
		map<string, int> mp;
		map<string, string> ans;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			set<string> st;
			int l = s.length();
			for (int j = 0; j < l; j++)
			{
				for (int k = 1; k <= l - j; k++)
				{
					string tmp = s.substr(j, k);
					st.insert(tmp);
				}
			}
			for (auto it: st) 
			{
				if (!mp.count(it)) mp[it] = 0;
				mp[it]++;
				ans[it] = s;
			}
		}
		cin >> q;
		for (int i = 0; i < q; i++)
		{
			cin >> s;
			if (!mp.count(s)) cout << "0 -" << endl;
			else 
			{
				cout << mp[s] << " " << ans[s] << endl;
			}
		}
	}
	return 0;
}
