#include <bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	while (cin >> s)
	{
		int n = s.length(), m = n - 1 >> 1;
		string ans = "";
		ans += s[m];
		int r = m + 1, l = m - 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (i % 2 == 0) ans += s[r++];
			else ans += s[l--];
		}
		cout << ans << endl;
	}
	return 0;
}