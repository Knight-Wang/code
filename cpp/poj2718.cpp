// poj2718.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;

bool in[10];
int t, n, num[10];
string s;
stringstream ss;
int minn = INF;

int main()
{
	cin >> t;
	getchar();
	while (t--)
	{
		getline(cin, s);
		ss.clear();
		n = 0;
		minn = INF;
		ss << s;
		while (ss >> num[n++]);
		n--;
		if (n == 2)
		{
			cout << abs(num[0] - num[1]) << endl;
			continue;
		}
		do
		{
			int x = 0, y = 0, z = 0;
			for (int i = 0; i < n / 2; i++)
			{
				x += num[i];
				if (i != n / 2 - 1)
					x *= 10;
			}
			for (int i = n / 2; i < n; i++)
			{
				y += num[i];
				if (i != n - 1)
					y *= 10;
				if (i == n / 2)
					continue;
				z += num[i];
				if (i != n - 1)
					z *= 10;
			}
			if (!(n > 3 && num[0] == 0 || num[n / 2] == 0))
				minn = min(minn, abs(x - y));
			if (n & 1 && !(num[0] == 0 || n > 3 && num[n / 2 + 1] == 0))
				minn = min(minn, abs(x * 10 + num[n / 2] - z));
		} while (next_permutation(num, num + n));
		cout << minn << endl;
	}
	//system("pause");
	return 0;
}

