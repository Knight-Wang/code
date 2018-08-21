#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length(), maxn = 0, cnt = 1, pos = -1;
		for (int i = 0; i < n - 1; i++)
		{
			if (s[i] == s[i + 1])
			{
				maxn = max(maxn, cnt);
				cnt = 1;
				pos = i;
			}
			else cnt++;
		}
		maxn = max(maxn, cnt);
		if (pos != -1)
		{
			int i = pos + 1; cnt = 1;
			while (i != pos && s[i] != s[(i + 1) % n])
			{
				i = (i + 1) % n;
				cnt++;
			}
			maxn = max(maxn, cnt);
		}
		cout << maxn << endl;
	}
	return 0;
}