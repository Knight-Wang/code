#include <iostream>
#include <cstdio>
using namespace std;

int a[3];

int main()
{
	int n, x;
	cin >> n >> x;
	int t = n % 6;
	a[x] = 1;
	while (t)
	{
		if (n & 1) swap(a[0], a[1]);
		else swap(a[1], a[2]);
		t--; n--;
	}
	int i = 0;
	for (; i < 3; i++)
		if (a[i]) break;
	cout << i << endl;
	return 0;
}