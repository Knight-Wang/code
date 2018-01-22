#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	cout << "100003 100003" << endl;
	for (int i = 0; i < n - 2; i++)
	{
		cout << i + 1 << " " << i + 2 << " " << 1 << endl;
	}
	cout << n - 1 << " " << n << " " << 100005 - n << endl;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 2; j <= n; j++)
		{
			if (cnt >= m - n + 1) break;
			cout << i << " " << j << " 1000000000" << endl;
			cnt++;
		}
	}
	return 0;
}