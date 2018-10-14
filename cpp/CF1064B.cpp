#include <iostream>
using namespace std;
int main()
{
	int t, k;
	cin >> t;
	while (t--)
	{
		cin >> k;
		int f = 0;
		while (k)
		{
			if (k & 1) f++;
			k >>= 1;
		}
		cout << (1 << f) << endl;
	}
	return 0;
}
