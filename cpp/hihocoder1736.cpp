#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int tot = n / (2 * k) * 2 * k;
		bool flg = false;
		for (int i = 0; i < tot; i++)
		{
			if (i % k == 0) flg = !flg;
			cout << (flg ? i + 1 + k : i + 1 - k) << " ";
		}
		if (n - tot <= k)
		{
			for (int i = n; i > tot; i--) cout << i << " ";
		}
		else
		{
			for (int i = tot; i < n - k; i++) cout << i + 1 + k << " ";
			for (int i = tot + k - 1; i >= n - k; i--) cout << i + 1 << " ";
			for (int i = tot + k; i < n; i++) cout << i + 1 - k << " ";
		}
		cout << endl;
	}
	return 0;
}