#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		string s;
		set<string> st;
		for (int i = 0; i < n; i++)
		{
			cin >> s;
			vector<char> v;
			for (int i = 0; i < s.length(); i++) v.push_back(s[i]);
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			string t = "";
			for (auto it: v) t += it;
			st.insert(t);
		}
		cout << st.size() << endl;
	}
	return 0;
}