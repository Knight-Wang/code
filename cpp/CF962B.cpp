#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a, b, x, y;
	string s;
	while (cin >> n >> a >> b >> s)
	{
		x = a; y = b;
		int i = 0;
		for (; i < n; i++)
		{
			if (s[i] == '*') continue;
			if (!a || !b) break;
			if (a >= b)
			{
				if (i != 0 && s[i - 1] == 'A') { s[i] = 'B'; b--; }
				else { s[i] = 'A'; a--; }
			}
			else
			{
				if (i != 0 && s[i - 1] == 'B') { s[i] = 'A'; a--; }
				else { s[i] = 'B'; b--; }
			}
		}
		if (a)
		{
			for (int j = i; j < n; j++)
			{
				if (!a) break;
				if (s[j] == '*') continue;
				a--; j++;
			}
		}
		if (b)
		{
			for (int j = i; j < n; j++)
			{
				if (!b) break;
				if (s[j] == '*') continue;
				b--; j++;
			}
		}
		cout << x + y - a - b << endl;
	}
	return 0;
}