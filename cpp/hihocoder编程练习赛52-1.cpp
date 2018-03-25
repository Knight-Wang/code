#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	string s, t;
	cin >> n >> t;
	map<char, int> mp;
	for (int i = 0; i < t.length(); i++) mp[t[i]] = i;
	vector<string> str;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		str.push_back(s);		
	}
	vector<pair<string, int>> vs;
	for (int i = 0; i < n; i++)
	{
		int l = str[i].length();
		string res = "";
		for (int j = 0; j < l; j++)
		{
			res += (char)(mp[str[i][j]] + 'a');
		}
		vs.push_back(make_pair(res, i));
	}
	sort(vs.begin(), vs.end());
	for (int i = 0; i < vs.size(); i++) cout << str[vs[i].second] << endl;
	return 0;
}
