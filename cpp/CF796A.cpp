#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int a[105];

int main()
{
	//freopen("C:\\users\\wangyiming\\Desktop\\in.txt", "r", stdin);
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int minn = INF, i = m - 1;
	bool flag = false;
	for (; i >= 1; i--)
	{
		if (a[i] && a[i] <= k)
		{			
			flag = true;
			break; 
		}
	}
	if (flag)
		minn = m - i; 
	i = m + 1;
	flag = false;
	for (; i <= n; i++)
	{
		if (a[i] && a[i] <= k) 
		{
			flag = true; 
			break;
		}
	}
	if (flag)
		minn = min(minn, i - m);
	printf("%d\n", minn * 10);
	return 0;
}