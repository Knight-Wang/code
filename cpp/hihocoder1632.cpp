#include <bits/stdc++.h>
using namespace std;
char a[105][105];
int n;
bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < n;
}

int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> a[i][j];
		string s;
		int x = 0, y = 0, cnt = n * n - 1;
		s += a[x][y];
		while (cnt > 0)
		{
			if (check(x, y + 1)) y++;
			else x++;
			s += a[x][y]; cnt--;
			while (check(x + 1, y - 1)) { x++; y--; s += a[x][y]; cnt--; }
			if (check(x + 1, y)) x++;
			else y++;
			s += a[x][y]; cnt--;
			while (check(x - 1, y + 1)) { x--; y++; s += a[x][y]; cnt--; }
		}
		x = 0, y = 0;
		int i = 1, t = 1;
		while (i < n * n)
		{
			while (y < n - t) { y++; a[x][y] = s[i++]; }
			while (x < n - t) { x++; a[x][y] = s[i++]; }
			while (y >= t) { y--; a[x][y] = s[i++]; }
			while (x > t) { x--; a[x][y] = s[i++]; }
			t++;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << a[i][j];
			cout << endl;
		}
	}
	return 0;
}