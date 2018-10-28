#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		int i = 2;
		for ( ; i * i <= n; i++)
		{
			int x = n;
			int cnt = 0;
			bool flg = true;
			while (x)
			{
				if (x % i == 1) cnt++;
				else if (x % i != 0) { flg = false; break; }
				x /= i;
			}
			if (flg && cnt == 2) cout << i << endl;
		}
		cout << n - 1 << endl;
	}
	return 0;
}