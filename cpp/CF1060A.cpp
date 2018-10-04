#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string s;
	while (cin >> n >> s)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '8') cnt++;
		}
		int maxn = 0;
		for (int i = 1; i <= cnt; i++)
		{
			maxn = max(maxn, min(i, (n - i) / 10));
		}
		cout << maxn << endl;
	}
	return 0;
}
