#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, p; string s;
	while (cin >> n >> p)
	{
		cin >> s;
		if (p >= n) { cout << "No" << endl; continue; }
		bool ok = false;
		for (int i = 0; i < p; i++)
		{
			bool flg = false;
			char tmp = s[i];
			if (tmp == '.' && i + p < n)
			{
				if (s[i + p] == '0') s[i] = '1';
				else if (s[i + p] == '1') s[i] = '0';
				else { s[i] = '1'; s[i + p] = '0'; }
				flg = true;
			}
			if (flg) { ok = true; break; }
			for (int j = i + p; j < n; j += p)
			{
				if (s[j] == '.')
				{
					if (tmp == '0') s[j] = '1';
					else s[j] = '0';
					flg = true; break;
				}
				else if (s[j] != tmp) { flg = true; break; }
			}
			if (flg) { ok = true; break; }
		}
		if (ok)
		{
			for (int i = 0; i < n; i++)
			{
				if (s[i] == '.') s[i] = '0';
			}
			cout << s << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}