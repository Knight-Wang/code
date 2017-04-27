// poj2676.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int now[9][9], row[9][10], col[9][10], block[3][3][10];
bool flag = false;

bool check(int x, int y, int i)
{
	if (!row[x][i] && !col[y][i] && !block[x / 3][y / 3][i])
	{
		row[x][i] = col[y][i] = block[x / 3][y / 3][i] = 1;
		return true;
	}
	return false;
}

void back_trace(int x, int y, int i)
{
	now[x][y] = row[x][i] = col[y][i] = block[x / 3][y / 3][i] = 0;
}

void dfs(int x, int y)
{
	if (flag)
		return;
	if (x == 9)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << now[i][j];
			}
			puts("");
		}
		flag = true;
		return;
	}
	int nx = (y == 8 ? x + 1 : x);
	int ny = (y == 8 ? 0 : y + 1);
	if (now[x][y])
		dfs(nx, ny);
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (check(x, y, i))
			{
				now[x][y] = i;
				dfs(nx, ny);
				back_trace(x, y, i);
			}
		}
	}
}
int main()
{
	cin >> n;
	char tmp;
	while (n--)
	{
		flag = false;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 1; j <= 9; j++)
			{
				row[i][j] = col[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int k = 1; k <= 9; k++)
					block[i][j][k] = 0;
			}
		}
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cin >> tmp;
				now[i][j] = tmp - '0';
				if (now[i][j])
				{
					row[i][now[i][j]] = 1;
					col[j][now[i][j]] = 1;
					block[i / 3][j / 3][now[i][j]] = 1;
				}
			}
		}
		dfs(0, 0);
	}
	//system("pause");
	return 0;
}

