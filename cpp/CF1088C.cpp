#include <bits/stdc++.h>
using namespace std;
int a[2005];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << n + 1 << endl;
		for (int i = n; i >= 1; i--)
		{
			int tmp = (i - a[i] % (n + 1) + n + 1) % (n + 1);
			cout << 1 << " " << i << " " << tmp << endl;
			for (int j = i; j >= 1; j--)
			{
				a[j] += tmp;
			}
		}
		cout << 2 << " " << n << " " << n + 1 << endl;
	}
	return 0;
}