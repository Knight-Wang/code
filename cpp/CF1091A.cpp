#include <bits/stdc++.h>
using namespace std;
int main()
{
	int y, r, b;
	while (cin >> y >> r >> b)
	{
		int tmp = y;
		while (tmp >= 1)
		{
			if (r >= tmp + 1 && b >= tmp + 2) break;
			tmp--;
		}
		cout << 3 * tmp + 3 << endl;
	}
	return 0;
}