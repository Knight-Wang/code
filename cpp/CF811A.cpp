#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	//freopen("D:\\codes\\tmp\\in.txt", "r", stdin);
	int x, y, dx = 1, dy = 2;
	cin >> x >> y;
	while (true)
	{
		x -= dx;
		if (x < 0)
		{
			cout << "Vladik" << endl;
			break;
		}
		y -= dy;
		if (y < 0)
		{
			cout << "Valera" << endl;
			break;
		}
		dx += 2;
		dy += 2;
	}
	return 0;
}