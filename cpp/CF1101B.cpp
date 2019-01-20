#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length();
		int l = n, r = -1;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ']') r = i;
		}
		for (int i = n - 1; i >= 0; i--)
		{
			if (s[i] == '[') l = i;
		}
		if (l != n && r != -1 && l < r)
		{
			int x = r, y = l;
			for (int i = l + 1; i < r; i++)
			{
				if (s[i] == ':') y = i;
			}
			for (int i = r - 1; i >= l + 1; i--)
			{
				if (s[i] == ':') x = i;
			}
			if (x != r && y != l && x < y)
			{
				int cnt = 0;
				for (int i = x + 1; i < y; i++)
				{
					if (s[i] == '|') cnt++;
				}
				cout << cnt + 4 << endl;
			}
			else cout << -1 << endl;
		}
		else cout << -1 << endl;
	}
	return 0;
}