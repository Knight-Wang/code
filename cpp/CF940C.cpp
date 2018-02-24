#include <bits/stdc++.h>
using namespace std;
int a[26];

int main()
{
	int n, k;
	string s;
	while (cin >> n >> k >> s)
	{
		memset(a, 0, sizeof a);
		for (int i = 0; i < n; i++) a[s[i] - 'a']++;
		vector<char> v;
		for (int i = 0; i < 26; i++) if (a[i]) v.push_back('a' + i);
		if (k > n) 
		{ 
			cout << s;
			for (int i = 0; i < k - n; i++) cout << v[0]; 
			cout << endl; continue; 
		}
		int t = k;
		while (s[t - 1] == v.back()) t--;
		int pos = lower_bound(v.begin(), v.end(), s[t - 1]) - v.begin();
		s[t - 1] = v[pos + 1];
		string ans = s.substr(0, t);
		for (int i = t; i < k; i++) ans.push_back(v[0]);
		cout << ans << endl;
	}
	return 0;
}