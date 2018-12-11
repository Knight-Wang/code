#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int t, x;
	cin >> t;
	while (t--)
	{
		cin >> x;
		int cnt = 0;
		for (int i = 1; i * i <= x - 1; i++)
		{
			if ((x - 1) % i == 0)
			{
				if ((x - 1) / i != i)
					cnt += 2;
				else cnt++;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}
