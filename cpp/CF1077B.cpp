#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n;
	while (cin >> n)
	{
		int cnt = 0;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 2; i < n; i++)
		{
			if (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1)
			{
				cnt++; a[i + 1] = 0;
			}
		}
		cout << cnt << endl;
	}
	return 0;
}