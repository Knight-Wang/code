#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
struct node
{
	pii d;
	int id;
};
node a[300005];
int n;
bool cmp(node x, node y)
{
	if (x.d.first != y.d.first) return x.d.first > y.d.first;
	return x.d.second < y.d.second;
}
int main()
{
	while (cin >> n)
	{
		for (int i = 0; i < n; i++) { cin >> a[i].d.first >> a[i].d.second; a[i].id = i; }
		sort(a, a + n, cmp);
		bool flg = false;
		int i = 0;
		for (; i < n - 1; i++)
		{
			if (a[i].d.first >= a[i + 1].d.first && a[i].d.second <= a[i + 1].d.second)
			{
				flg = true; break;
			}
		}
		if (flg)
		{
			cout << a[i].id + 1 << " " << a[i + 1].id + 1 << endl;
		}
		else
		{
			cout<< -1 << " " << -1 << endl;
		}
	}
	return 0;
}