#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	int n, k;
	while (cin >> n >> k)
	{
		int ans = INF;
		for (int i = 1; i <= k - 1; i++)
		{
			if (n % i == 0)
			{
				int tmp = n / i;
				ans = min(ans, tmp * k + i);
			}
		}
		cout << ans << endl;
	}
	return 0;
}