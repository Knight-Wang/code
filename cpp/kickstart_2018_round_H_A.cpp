#include <bits/stdc++.h>
using namespace std;
bool cmp(string a, string b)
{
	if (a.length() != b.length()) return a.length() < b.length();
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != b[i]) return a[i] < b[i];
	}
	return true;
}
int main()
{
	int T, n, p;
	string s; 
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		cin >> n >> p;
		vector<string> v;
		for (int i = 0; i < p; i++) { cin >> s; v.push_back(s); }
		sort(v.begin(), v.end(), cmp);
		vector<string> ans;
		for (int i = v.size() - 1; i >= 0; i--)
		{
			bool flg = true;
			for (int j = 0; j < i; j++)
			{
				if (v[i].substr(0, v[j].length()) == v[j]) { flg = false; break; }
			}
			if (flg) ans.push_back(v[i]);
		}
		long long res = 1ll << n;
		for (auto it: ans) 
		{
			res -= (1ll << n - it.length());
		}
		cout << res << endl;
	}
	return 0;
}