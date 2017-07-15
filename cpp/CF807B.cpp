#include <iostream>
#include <cstdio>
using namespace std;

bool check(int p, int x, int y)
{
	for (int k = 0; x - k * 50 >= y; k++)
	{
		int tmp = x - 50 * k;
		int i = tmp / 50 % 475;
		for (int j = 0; j < 25; j++)
		{
			i = (i * 96 + 42) % 475;
			if (26 + i == p) return true;		
		}
	}
	return false;
}

int main()
{
	int p, x, y;
	cin >> p >> x >> y;
	int cnt = 0;
	while (!check(p, x + cnt * 100, y)) cnt++;
	cout << cnt << endl;
	return 0;
}