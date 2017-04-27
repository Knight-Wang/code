// CF758C.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
ll n, m, k, x, y, maxn, minn, t;
int main()
{
	cin >> n >> m >> k >> x >> y;
	if (n == 1)
	{
		maxn = k / m + (k % m ? 1 : 0);
		minn = k / m;
		t = y > k % m ? minn : maxn;
		cout << maxn << " " << minn << " " << t << endl;
	}
	else
	{
		ll t = (2 * n - 2) * m;
		ll tmp = k / t;
		ll rem = k % t;
		maxn = n > 2 ? 2 * tmp : tmp, minn = tmp;
		t = (x == 1 || x == n) ? minn : maxn;
		if (rem)
		{
			if (rem > n * m)
			{
				maxn += 2;
				minn++;
				ll p = (rem - n * m) / m;
				ll q = (rem - n * m) % m;
				ll nx = n - 1 - p;
				ll ny = q;
				if (ny == 0)
				{
					nx++;
					ny = m;
				}
				if (x < nx || x == nx && y > ny || x == n)
				{
					t++;
				}
				else
				{
					t += 2;
				}
			}
			else if (rem == n * m)
			{
				maxn++;
				minn++;
				t++;
			}
			else
			{
				if (rem > m)
					maxn++;
				else if (maxn == minn)
					maxn++;
				ll nx = rem / m;
				ll ny = rem % m;
				if (ny)
				{
					nx++;
				}
				else
				{
					ny = m;
				}
				if (!(x > nx || x == nx && y > ny))
				{
					t++;
				}
			}
		}
		cout << maxn << " " << minn << " " << t << endl;
	}
	//system("pause");
	return 0;
}

