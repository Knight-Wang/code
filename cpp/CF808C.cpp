#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

struct node
{
	int index, init, val;
};
node a[MAXN];

bool cmp(const node & a, const node & b)
{
	return a.val < b.val;
}

bool cmp2(const node & a, const node & b)
{
	return a.index < b.index;
}

int main()
{
	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].val;
		a[i].init = a[i].val;
		a[i].index = i;
	}
	sort(a, a + n, cmp);
	bool flg = true;
	for (int i = n - 1; i >= 0; i--)
	{
		int tmp = (a[i].val + 1) / 2;
		if (w - tmp < 0)
		{
			flg = false; break;
		}
		w -= tmp;
		a[i].val -= tmp;
	}
	if (!flg) puts("-1");
	else
	{
		int i = n - 1;
		for (; w ; i = (i - 1 + n) % n)
		{
			if (a[i].val) 
			{
				w--;
				a[i].val--;
			}
		}
		sort(a, a + n, cmp2);
		for (int i = 0; i < n; i++)
			cout << a[i].init - a[i].val << " ";
		cout << endl;
	}
	return 0;
}