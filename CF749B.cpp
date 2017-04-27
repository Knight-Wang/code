// CF749B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
int x[3], y[3];
int main()
{
	for (int i = 0; i < 3; i++)
	{
		cin >> x[i] >> y[i];
	}
	puts("3");
	int ax, ay, bx, by;
	ax = x[1] - x[0]; ay = y[1] - y[0];
	bx = x[2] - x[0]; by = y[2] - y[0];
	ax += bx; ay += by;
	ax += x[0]; ay += y[0];
	cout << ax << " " << ay << endl;
	ax = x[0] - x[1]; ay = y[0] - y[1];
	bx = x[2] - x[1]; by = y[2] - y[1];
	ax += bx; ay += by;
	ax += x[1]; ay += y[1];
	cout << ax << " " << ay << endl;
	ax = x[0] - x[2]; ay = y[0] - y[2];
	bx = x[1] - x[2]; by = y[1] - y[2];
	ax += bx; ay += by;
	ax += x[2]; ay += y[2];
	cout << ax << " " << ay << endl;
	//system("pause");
	return 0;
}

