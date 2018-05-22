#include <bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n / 2; i++) cin >> a[i];
		sort(a + 1, a + n / 2 + 1);
		int cnt = 0, cnt2 = 0, now = 1;
		for (int i = 1; i <= n / 2; i++)
		{
			cnt += abs(a[i] - now);
			now += 2;
		}
		now = 2;
		for (int i = 1; i <= n / 2; i++)
		{
			cnt2 += abs(a[i] - now);
			now += 2;
		}
		cout << min(cnt, cnt2) << endl;
	}
	return 0;
}