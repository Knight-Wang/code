#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int c[1005][1005];

const int mod = 1e9 + 7;

void init()
{
	c[0][0] = 1;
	for (int i = 1; i <= 1000; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
}
int main()
{
	int t, n, m;
	init();
	cin >> t;
	while (t--)
	{
		cin >> n >> m;	
		int x = min(n, m), y = max(n, m);
		cout << c[y][x] << endl;
	}
	return 0;
}