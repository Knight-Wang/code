#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int a[10005], n, m, l, r, x;
int main()
{
	//freopen("d:\\codes\\tmp\\in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> l >> r >> x;
		l--; r--; x--;
		int tmp = a[x], cnt = 0;
		for (int j = l; j <= r; j++)
		{
			if (j != x && a[j] < tmp) cnt++;
		}
		if (cnt == x - l)
			cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}