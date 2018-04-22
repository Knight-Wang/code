#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		if (s.length() < 4) { cout << 0 << endl; continue; }
		int ans = 0, last = 0;
		for (int i = 0; i < s.length() - 3; i++)
		{
			if (s.substr(i, 4) == "bear")
			{
				int tmp = (i - last + 1) * (s.length() - (i + 3));
				ans += tmp;
				last = i + 1;
			}
		}
		cout << ans << endl;
	}
	return 0;
}