#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 50;

int a[MAXN + 5][MAXN + 5], n;

bool check()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] == 1) 
				continue;
			bool flag = false;
			for (int p = 0; p < n; p++)
			{
				if (flag) break;
				for (int q = 0; q < n; q++)
				{
					if (a[i][p] + a[q][j] == a[i][j])
					{
						flag = true;
						break;
					}
				}
			}
			if (!flag) return false;
		}
	}
	return true;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	if (check()) puts("Yes");
	else puts("No");
	return 0;
}