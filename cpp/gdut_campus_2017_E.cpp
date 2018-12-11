// 倒水.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t, n, k;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		int cnt = 0;
		int tmp = n;
		while (tmp)
		{
			if (tmp & 1)
				cnt++;
			tmp >>= 1;
		}
		int now = 0;
		int ans = 0;
		int i = 0, t = 0;
		while (n)
		{
			if (n & 1)
				now++;
			if (now == cnt - k + 1)
			{
				break;
			}
			ans += n & 1 ? (1 << i) : 0;
			t += 1 << i;
			n >>= 1;
			i++;
		}
		ans |= ~t;
		ans = ~ans + 1;
		cout << ans << endl;
	}
	//system("pause");
	return 0;
}

