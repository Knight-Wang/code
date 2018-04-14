#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int a[MAXN], n;
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		int sum = accumulate(a, a + n, 0), sum2 = 0, i = 0;
		for (; i < n; i++)
		{
			if (sum2 + a[i] >= sum + 1 >> 1) break;
			sum2 += a[i];
		}
		cout << i + 1 << endl;
	}
	return 0;
}