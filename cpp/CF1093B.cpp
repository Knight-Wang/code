#include <bits/stdc++.h>
using namespace std;
int a[30];
int main()
{
	int n; string s;
	cin >> n;
	while (n--)
	{
		cin >> s;
		memset(a, 0, sizeof a);
		int cnt = 0;
		for (int i = 0; i < s.length(); i++) 
		{
			if (a[s[i] - 'a'] == 0) cnt++;
			a[s[i] - 'a']++;
		}
		if (cnt == 1) { cout << -1 << endl; continue; }
		sort(s.begin(), s.end());
		cout << s << endl;
	}
	return 0;
}