#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	return !b ? a : gcd(b, a % b);
}

int n, a[100005];

int main()
{
	cin >> n;
	int g = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (!i) g = a[i];
		else g = gcd(g, a[i]);
	}
	if (g > 1)
	{
		puts("YES\n0\n"); return 0;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (!(a[i] & 1)) continue;
		else if (i + 1 < n)
		{
			if (a[i + 1] & 1) cnt++;
			else cnt += 2;
			i++;
		}
		else cnt += 2;
	}
	cout << "YES" << endl << cnt << endl;
	return 0;
}