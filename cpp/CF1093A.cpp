#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, x;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x % 2 == 0) cout << x / 2 << endl;
		else cout << 1 + (x - 3) / 2 << endl;
	}
	return 0;
}