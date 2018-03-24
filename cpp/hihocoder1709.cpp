#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	set<vector<int>> st;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		int l = s.length();
		vector<int> v;
		for (int j = 1; j < l; j++)
		{
			v.push_back((s[j] - s[j - 1] + 26) % 26);
		}
		st.insert(v);
	}
	cout << st.size() << endl;
	return 0;
}
