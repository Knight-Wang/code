#include <bits/stdc++.h>
using namespace std;
const long long INF = 10000000000;
double dis(double x1, double y1, double x2, double y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int main()
{
	int a, b, c;
	double x1, x2, y1, y2;
	while (cin >> a >> b >> c)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		if (a == 0 || b == 0)
		{
			printf("%.10f\n", fabs(x1 - x2) + fabs(y1 - y2));
			continue;
		}
		double n1 = x1, m1 = y2; // y1--y2
		double ty = (-a * x1 - c) / b;
		double tx = (-b * y2 - c) / a;
		double ans = fabs(x1 - x2) + fabs(y1 - y2);
		if (ty >= min(y1, y2) && ty <= max(y1, y2) && tx >= min(x1, x2) && tx <= max(x1, x2))
		{
			double tmp = fabs(y1 - ty) + fabs(x2 - tx) + dis(x1, ty, tx, y2);
			ans = min(ans, tmp);
		}
		double ty2 = (-a * x2 - c) / b;
		if (ty >= min(y1, y2) && ty <= max(y1, y2) && ty2 >= min(y1, y2) && ty2 <= max(y1, y2))
		{
			double tmp = fabs(y1 - ty) + fabs(ty2 - y2) + dis(x1, ty, x2, ty2);
			ans = min(ans, tmp);
		}
		double n2 = x2, m2 = y1; // x1--x2
		tx = (-b * y1 - c) / a;
		ty = (-a * x2 - c) / b;
		if (ty >= min(y1, y2) && ty <= max(y1, y2) && tx >= min(x1, x2) && tx <= max(x1, x2))
		{
			double tmp = fabs(x1 - tx) + fabs(y2 - ty) + dis(tx, y1, x2, ty);
			ans = min(ans, tmp);
		}
		double tx2 = (-b * y2 - c) / a;
		if (tx >= min(x1, x2) && tx <= max(x1, x2) && tx2 >= min(x1, x2) && tx2 <= max(x1, x2))
		{
			double tmp = fabs(x1 - tx) + fabs(tx2 - x2) + dis(tx, y1, tx2, y2);
			ans = min(ans, tmp);
		}
		printf("%.10f\n", ans);
	}
	return 0;
}