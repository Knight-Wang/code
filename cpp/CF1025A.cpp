#include <bits/stdc++.h>
using namespace std;
int cnt[30];
int main()
{
	int n;
	string s;
	while (cin >> n)
	{
		memset(cnt, 0, sizeof cnt);
		cin >> s;
		for (int i = 0; i < n; i++) cnt[s[i] - 'a']++;
		int x = 0, y = 0;
		for (int i = 0; i < 26; i++)
		{
			if (cnt[i] == 1) x++;
			else if (cnt[i] >= 2) y++;
		}
		cout << (y >= 1 || x == 1 ? "Yes" : "No") << endl;
	}
	return 0;
}