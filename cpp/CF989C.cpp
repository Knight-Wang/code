#include <bits/stdc++.h>
using namespace std;
char ans[51][51];
void fillin(int x, int y, char c, int maxy, int cnt)
{
	int a = x, b = y;
	while (cnt)
	{
		ans[a][b] = c;
		if (b + 2 >= maxy) { a += 2; b = y; }
		else b += 2;
		cnt--;
	}
}
int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 25; j++)
			{
				ans[i][j] = 'A';
				ans[i][j + 25] = 'B';
				ans[i + 25][j] = 'C';
				ans[i + 25][j + 25] = 'D';
			}
		}
		fillin(1, 1, 'B', 25, b - 1);
		fillin(1, 26, 'C', 50, c - 1);
		fillin(26, 1, 'D', 25, d - 1);
		fillin(26, 26, 'A', 50, a - 1);
		cout << "50 50" << endl;
		for (int i = 0; i < 50; i++)
		{
			for (int j = 0; j < 50; j++)
				cout << ans[i][j];
			cout << endl;
		}
	}
	return 0;
}