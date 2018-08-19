#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T, n;
	string s;
	cin >> T;
	while (T--)
	{
		cin >> n >> s;
		int l = 0, r = n - 1;
		bool flg = true;
		while (l <= r)
		{
			int tmp = abs(s[l] - s[r]);
			if (tmp != 2 && tmp != 0)
			{
				flg = false; break;
			}
			l++;
			r--;
		}
		cout << (flg ? "YES" : "NO") << endl;
	}
	return 0;
}