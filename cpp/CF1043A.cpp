#include <iostream>
using namespace std;
int a[105], n;
bool check(int x)
{
	int p = 0, q = 0;
	for (int i = 0; i < n; i++)
	{
		p += a[i]; q += x - a[i];
	}
	return q > p;
}
int main()
{
	while (cin >> n)
	{
		int maxn = 0;
		for (int i = 0; i < n; i++) 
		{
			cin >> a[i];
			maxn = max(maxn, a[i]);
		}
		int i = maxn;
		for ( ; ; i++)
		{
			if (check(i)) break;
		}
		cout << i << endl;
	}
	return 0;
}