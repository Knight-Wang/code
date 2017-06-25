#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int x1, y1, x2, y2, dx, dy;
	cin >> x1 >> y1 >> x2 >> y2 >> dx >> dy;
	int m = abs(x1 - x2), n = abs(y1 - y2);
	if (m % dx || n % dy) puts("NO");
	else if ((m / dx & 1) != (n / dy & 1)) puts("NO");
	else puts("YES");
	return 0;
} 