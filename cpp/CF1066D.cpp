#include <iostream>
using namespace std;
int a[200005];
int main()
{
	int n, m, k;
	while (cin >> n >> m >> k)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		int now = n - 1, sum = 0, cnt = 0;
		while (now >= 0)
		{
			if (sum + a[now] <= k)
			{
				sum += a[now--];
				cnt++;
			}
			else if (a[now] > k)
			{
				break;
			}
			else
			{
				m--;
				if (m == 0) break;
				sum = 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
