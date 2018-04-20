#include <bits/stdc++.h>
using namespace std;
int main()
{
	int m, n;
	while (cin >> m >> n)
	{
		n >>= 1;
		cout << 2 * (n * m - n * (n - 1) / 2) + m - n << endl;
	}
	return 0;
}