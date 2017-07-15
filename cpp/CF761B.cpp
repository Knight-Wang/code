#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 55;
int n, L, a[MAXN], b[MAXN], ita[MAXN], itb[MAXN];
int main()
{
	cin >> n >> L;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n - 1; i++)
	{
		ita[i] = a[i + 1] - a[i];
		itb[i] = b[i + 1] - b[i];
	}
	ita[n - 1] = L - a[n - 1] + a[0];
	itb[n - 1] = L - b[n - 1] + b[0];
	bool flg = false;
	for (int i = 0; i < n; i++) // itb起点
	{
		bool ok = true;
		for (int j = 0; j < n; j++)
		{
			if (ita[j] != itb[(j + i) % n])
			{
				ok = false; break;
			}
		}
		if (ok)
		{
			flg = true; break;
		}
	}
	cout << (flg ? "YES" : "NO") << endl;
	return 0;
}