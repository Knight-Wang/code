#include <iostream>
#include <cstdio>
using namespace std;

bool judge(int y)
{
	if (y % 100 && y % 4 == 0) return true;
	else if (y % 400 == 0) return true;
	return false;
}

int days(int y, int m)
{
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	if (m == 2)
	{
		if (judge(y)) return 29;
		return 28;
	}
	return 30;
}

int check(int now, int y, int m, int d)
{
	if (m == 2 && d == 29 && !judge(y)) return -1;
	int sum = now;
	for (int i = 1; i <= m - 1; i++) sum += days(y, i);
	sum += d - 1;
	return sum % 7;
}

int main()
{
	int n, y, m, d;
	cin >> n;
	while (n--)
	{
		scanf("%d-%d-%d", &y, &m, &d);
		int now = 0, sum = 0;
		for (int i = 2017; i < y; i++) 
		{
			int tmp = judge(i) ? 366 : 365;
			now += tmp; sum += tmp;
		}
		for (int i = 1; i <= m - 1; i++) now += days(y, i);
		now += d - 1; now %= 7;
		int i = y + 1;
		for (; i <= 9999; i++)
		{
			sum += judge(i - 1) ? 366 : 365;
			if (check(sum % 7, i, m, d) == now) break;
		}
		cout << i << endl;
	}
	return 0;
}