#include <iostream>
#include <cstdio>
using namespace std;

int W, S, X, Y;
int a[10005][105];
int b[105];

int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	cin >> W >> S >> X >> Y;
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < X; j++)
			cin >> a[i][j];
	}
	int tmp;
	for (int i = 0; i < S; i++)
	{
		for (int j = 0; j < X; j++)
		{
			cin >> tmp;
			b[j] = max(b[j], tmp);
		}
	}
	for (int i = 0; i < W; i++)
	{
		for (int j = 0; j < X; j++)
		{
			a[i][j] = min(a[i][j], Y - b[j]);
		}
		for (int j = 0; j < X; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}