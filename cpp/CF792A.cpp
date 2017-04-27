// CF792A.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = 0x3f3f3f3f3f3f3f3f;

int a[200005], n;

int main()
{
	ll minn = INF;
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i + 1] - a[i] < minn)
		{
			minn = a[i + 1] - a[i];
			num = 1;
		}
		else if (a[i + 1] - a[i] == minn)
		{
			num++;
		}
	}
	cout << minn << " " << num << endl;
	//system("pause");
	return 0;
}

