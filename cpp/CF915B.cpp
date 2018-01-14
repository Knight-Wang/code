#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, p, l, r;
	while (cin >> n >> p >> l >> r)
	{
		if (p >= l && p <= r)
		{
			if (l == 1 && r == n) cout << 0 << endl;
			else if (l == 1) cout << r - p + 1 << endl;
			else if (r == n) cout << p - l + 1 << endl;
			else cout << min(p - l + 1, r - p + 1) + r - l + 1 << endl;
		}
		else if (p > r) 
		{
			int tmp = p - r + 1;
			if (l != 1) tmp += r - l + 1;
			cout << tmp << endl;
		}
		else
		{
			int tmp = l - p + 1;
			if (r != n) tmp += r - l + 1;
			cout << tmp << endl;
		}
	}
	return 0;
}