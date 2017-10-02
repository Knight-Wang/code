#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[4][4005];
int buf[16000005];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> a[j][i];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buf[i * n + j] = a[0][i] + a[1][j];
		}
	}
	sort(buf, buf + n * n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int tmp = -a[2][i] - a[3][j];
			if (binary_search(buf, buf + n * n, tmp))
			{
				int l = lower_bound(buf, buf + n * n, tmp) - buf;
				int r = upper_bound(buf, buf + n * n, tmp) - buf;
				cnt += r - l;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}