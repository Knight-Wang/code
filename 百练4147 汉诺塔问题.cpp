// 百练4147 汉诺塔问题.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int n;
char a, b, c;
vector<int> p, q, r;
void hanoi(char x, char y, char z, int n)
{
	if (n == 1)
	{
		cout << p[0] << ":" << x << "->" << z << endl;
		r.push_back(p[0]);
		return;
	}
	hanoi(x, z, y, n - 1);
	cout << p[n - 1] << ":" << x << "->" << z << endl;
	r.push_back(p[n - 1]);
	hanoi(y, x, z, n - 1);
}
int main()
{
	cin >> n >> a >> b >> c;
	
	for (int i = 1; i <= n; i++)
		p.push_back(i);
	hanoi(a, b, c, n);
	//system("pause");
	return 0;
}

