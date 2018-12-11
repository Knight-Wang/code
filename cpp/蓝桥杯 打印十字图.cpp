#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {-1, 0, 0, 1};
const int Dx[4] = {1, -1, -1, 1};
const int Dy[4] = {-1, 1, -1, 1};
int a[MAXN][MAXN];
void show(int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j]) cout << '$';
			else cout << '.';
		}
		cout << endl;
	}
}
int main()
{
	int x;
	cin >> x;
	int n = 9 + (x - 1) * 4;
	int cx = n >> 1, cy = n >> 1;
	a[cx][cy] = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			int nx = cx + dx[i] * j, ny = cy + dy[i] * j;
			a[nx][ny] = 1;
		}
	}
	for (int i = 0; i < x; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int d = (i + 1) * 2 + 2;
			int nx = cx + dx[j] * d, ny = cy + dy[j] * d;
			a[nx][ny] = 1;
			for (int k = 0; k < (i + 1) * 2; k++)
			{
				if (j == 0 || j == 3) a[nx - (k + 1)][ny] = a[nx + (k + 1)][ny] = 1;	
				else a[nx][ny - (k + 1)] = a[nx][ny + (k + 1)] = 1;
			}
		}
		for (int j = 0; j < 4; j++)
		{
			int d = (i + 1) * 2;
			int nx = cx + Dx[j] * d, ny = cy + Dy[j] * d;
			a[nx][ny] = a[nx + Dx[j]][ny] = a[nx][ny + Dy[j]] = 1;
		}
	}
	show(n);
	return 0;
}
