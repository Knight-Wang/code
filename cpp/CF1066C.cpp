#include <iostream>
#include <cstring>
using namespace std;
int a[200005];
int main()
{
	int q;
	while (cin >> q)
	{
		char t;
		memset(a, 0, sizeof a);
		int x, l = 100000, r = 100000;
		for (int i = 0; i < q; i++)
		{
			cin >> t >> x;
			if (t == 'L')
			{
				a[x] = l--;
				if (i == 0) r++;
			}
			else if (t == 'R')
			{
				a[x] = r++;
				if (i == 0) l--;
			}
			else
			{
				cout << min(a[x] - l, r - a[x]) - 1 << endl;
			}
		}
	}
	return 0;
}
