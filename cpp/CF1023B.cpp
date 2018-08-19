#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long n, k;
	while (cin >> n >> k)
	{
		if (k > 2 * n - 1) { cout << 0 << endl; continue; }
		else if (n >= k - 1) cout << (k - 1) / 2 << endl;
		else cout << (k - 1) / 2 - (k - 1 - n) << endl;
	}
	return 0;
}