#include <bits/stdc++.h>
using namespace std;

int a[5000005];

int main()
{
	int T, n;
	string s; 
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cout << "Case #" << t << ": ";
		cin >> n >> s;
		for (int i = 1; i <= n; i++) a[i] = s[i - 1] - '0';
		int sum = 0, maxn = 0;
		for (int i = 1; i <= (n + 1) / 2; i++) sum += a[i];
		maxn = max(maxn, sum);
		for (int i = (n + 1) / 2 + 1; i <= n; i++)
		{
			sum -= a[i - (n + 1) / 2];
			sum += a[i];
			maxn = max(maxn, sum);
		}
		cout << maxn << endl;
	}
	return 0;
}