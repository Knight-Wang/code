#include <iostream>
using namespace std;

const int N = 1005;

int a[N], b[N], cnt[N], n, x, y;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i], cnt[a[i]]++;
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++)
	{
		if (cnt[i] == 2) x = i;
		else if (cnt[i] == 0) y = i;
	}
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			a[i] = y;
			int bad = 0;
			for (int j = 0; j < n; j++)
				if (b[j] != a[j]) bad++;
			if (bad == 1)
			{
				for (int j = 0; j < n; j++) cout << a[j] << " ";
				return 0;
			}
			a[i] = x;
		}
	}
	return 0;
}