#include <iostream>
#include <vector>
using namespace std;
int a[1005], b[1005], n;
int main()
{
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++)
		{
			b[i] = a[i] - a[i - 1];
		}
		vector<int> v;
		for (int i = 1; i <= n; i++)
		{
			bool flg = true;
			for (int k = 1; k <= i; k++)
			{
				for (int j = k; j <= n; j += i)
				{
					if (j + i <= n && b[j] != b[j + i])
					{
						flg = false; break;
					}
				}
				if (!flg) break;
			}
			if (flg) v.push_back(i);
		}
		cout << v.size() << endl;
		for (auto it: v) cout << it << " ";
		cout << endl;
	}
	return 0;
}