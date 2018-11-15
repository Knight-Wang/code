#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		int maxn = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				if (a[j] - a[i] == j - i)
				{
					if (i == 1 && a[j] == j) maxn = max(maxn, j - 1);
					else if (a[j] == 1000) maxn = max(maxn, j - i);
					else if (j - i > 1) maxn = max(maxn, j - i - 1);
				}
			}
		}
		cout << maxn << endl;
	}
	return 0;
}