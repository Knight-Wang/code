#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int a[100005], n;
string b;
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) cin >> a[i];
		cin >> b;
		int l = -INF, r = INF;
		for (int i = 4; i < n; i++)
		{
			if (b[i] != b[i - 1])
			{
				if (b[i] == '0' && b[i - 1] == '1' && b[i - 2] == '1' && b[i - 3] == '1' && b[i - 4] == '1')
				{
					int tmp = INF; for (int j = i - 4; j <= i; j++) tmp = min(tmp, a[j]); 
					if (r >= tmp) r = tmp - 1;
				}
				else if (b[i] == '1' && b[i - 1] == '0' && b[i - 2] == '0' && b[i - 3] == '0' && b[i - 4] == '0')
				{
					int tmp = -INF; for (int j = i - 4; j <= i; j++) tmp = max(tmp, a[j]); 
					if (l <= tmp) l = tmp + 1;
				}
			}
		}
		cout << l << " " << r << endl;
	}
	return 0;
}