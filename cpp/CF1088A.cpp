#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	while (cin >> x)
	{
		bool flg = false;
		for (int i = 1; i <= x; i++)
		{
			if (flg) break;
			for (int j = 1; j <= x; j++)
			{
				if (i % j == 0 && i * j > x && i / j < x)
				{
					cout << i << " " << j << endl;
					flg = true;
					break;
				}
			}
		}
		if (!flg) cout << -1 << endl;
	}
	return 0;
}