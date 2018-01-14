#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, k, x, maxn = -1;
	while (cin >> n >> k)
	{
		maxn = -1;
		for (int i = 0; i < n; i++) 
		{ 
			cin >> x; 
			if (k % x == 0) maxn = max(maxn, x);
		}
		cout << k / maxn << endl;
	}
	return 0;
}