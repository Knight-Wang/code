#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	string s, t;
	while (cin >> n >> m)
	{
		cin >> s >> t;
		int i = 0;
		for ( ; i < n; i++)
		{
			if (s[i] == '*') break;
		}
		if (i == n)
		{
			if (n == m && s == t) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
		else
		{
			if (n > m + 1) { cout << "NO" << endl; continue; }
			string p = "", q = "";
			if (i != 0) p = s.substr(0, i);
			if (i != n - 1) q = s.substr(i + 1, n - i - 1);
			bool flg = true;
			if (p != "" && t.substr(0, i) != p) flg = false;
			if (q != "" && t.substr(m - (n - i - 1), n - i - 1) != q) flg = false;
			cout << (flg ? "YES" : "NO") << endl;
		}
	}
	return 0;
}