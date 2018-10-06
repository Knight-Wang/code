#include <iostream>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1) { cout << 1 << endl; continue; }
		int x = 1;
		while (n >= 4)
		{
			for (int i = 1; i <= (n + 1) / 2; i++)
			{
				cout << x << " ";
			}
			n /= 2;
			x *= 2;
		}
		if (n == 2) { cout << x << " " << x * 2 << endl; }
		else { cout << x << " " << x << " " << x * 3 << endl; }
	}
	return 0;
}
