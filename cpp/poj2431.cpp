#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
	int d, f;
};
node a[10005];
bool cmp(node a, node b)
{
	return a.d > b.d;
}
int main()
{
	int n, l, p;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[n - 1 - i].d >> a[n - 1 - i].f;
	sort(a, a + n, cmp);
	cin >> l >> p;
	for (int i = 0; i < n; i++) a[i].d = l - a[i].d;
	priority_queue<int> q;
	int i = 0, rem = p, cnt = 0;
	for ( ; i < n; i++) 
	{ 
		if (a[i].d > rem) break; 
		q.push(a[i].f); 
	}
	while (!q.empty())
	{
		if (rem >= l) break;
		rem += q.top(); q.pop();
		cnt++;
		for ( ; i < n; i++) 
		{ 
			if (a[i].d > rem) break; 
			q.push(a[i].f); 
		}
	}
	cout << (rem >= l ? cnt : -1) << endl;
	return 0;
}