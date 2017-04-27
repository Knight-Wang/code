// eight.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
using namespace std;

const double eps = 1e-6;

struct Point
{
	double x, y;
};

struct segment
{
	Point a, b;
};

segment t[105];
struct Vector
{
	double x, y;
	Vector(int xx, int yy) :x(xx), y(yy) { }
	Vector() { }
};

Vector operator - (const Point & p1, const Point & p2)
{ 
	return Vector(p1.x - p2.x, p1.y - p2.y);
}

double Cross(const Vector & v1, const Vector & v2)
{ 
	return v1.x * v2.y - v1.y * v2.x;
}

bool IsFormalCross(Point p1, Point p2, Point p3, Point p4)
{
	return Cross(p2 - p1, p3 - p1) * Cross(p2 - p1, p4 - p1) < -eps && Cross(p4 - p3, p1 - p3) * Cross(p4 - p3, p2 - p3) < -eps;
}
int main()
{
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i].a.x >> t[i].a.y >> t[i].b.x >> t[i].b.y;
		for (int j = 0; j < i; j++)
		{
			if (IsFormalCross(t[i].a, t[i].b, t[j].a, t[j].b))
			{
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}

