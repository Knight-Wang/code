#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		double x, y, ans = 0x3f3f3f3f;
		for (int i = 0; i < n; i++)
		{
			cin >> x >> y;
			ans = min(ans, x / y);
		}
		printf("%.8f\n", ans * m);
	}
	return 0;
}