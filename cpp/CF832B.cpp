#include <iostream>
using namespace std;

string a, b;
int m, x, y, ok[30];

bool solve()
{
	if (y < x - 1) return false;
	int i = 0, j = 0;
	for (; i < x; i++, j++)
	{
		if (a[i] >= 'a' && a[i] <= 'z')
		{
			if (a[i] != b[j]) return false;
		}
		else if (a[i] == '?')
		{
			if (!ok[b[j] - 'a']) return false;
		}
		else
		{
			int tmp = j;
			for (; j < tmp + y - x + 1; j++)
			{
				if (ok[b[j] - 'a']) return false;
			}
			j--;
		}
	}
	return j == y;
}

int main()
{	
	string str;
	cin >> str;
	int n = str.length();
	for (int i = 0; i < n; i++)
	{
		ok[str[i] - 'a'] = 1;
	}
	cin >> a >> m;
	x = a.length();
	for (int i = 0; i < m; i++)
	{
		cin >> b;
		y = b.length();
		if (solve()) puts("YES");
		else puts("NO");
	}
	return 0;
}