#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, x, y, p;
	while (cin >> n >> x >> y)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			cin >> p; if (p <= x) cnt++; 
		}
		if (x > y) { cout << n << endl; continue; }
		cout << (cnt + 1 >> 1) << endl;
	}	
	return 0;
}