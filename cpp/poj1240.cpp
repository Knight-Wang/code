#include <iostream>
using namespace std;

int m, c[25][25], ans = 1;
string x, y;

void init(int m)
{
	c[0][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		c[i][0] = 1;
		for (int j = 1; j <= i; j++)
			c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
	}
}

void dfs(int lx, int rx, int ly, int ry)
{
	if (lx > rx) return;
	int cnt = 0; 
	while (lx <= rx)
	{
		int pos = ly;
		while (pos < ry && y[pos] != x[lx]) pos++;
		dfs(lx + 1, lx + pos - ly, ly, pos - 1); 
		lx += pos - ly + 1;
		ly = pos + 1;
		cnt++;
	}
	ans *= c[m][cnt];
}

int main()
{
	//freopen("d:\\codes\\tmp\\in.txt", "r", stdin);
	init(21);
	while (cin >> m, m)
	{
		ans = 1;
		cin >> x >> y;
		int len = x.length();
		dfs(1, len - 1, 0, len - 2);
		cout << ans << endl;
	}
	return 0;
}