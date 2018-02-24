#include <bits/stdc++.h>
using namespace std;

int main()
{
	int k;
	while (cin >> k)
	{
		if (k > 36) cout << -1 << endl;
		else 
		{
			for (int i = 0; i < k / 2; i++)
			{
				cout << 8;
			}
			if (k % 2) cout << 4;
			cout << endl;
		}
	}
	return 0;
}