#include <bits/stdc++.h>
using namespace std;
struct node
{
	int x, y, id;	
};
node a[1005], b[1005];
bool cmp(node & a, node & b)
{
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}
bool cmp2(node & a, node & b)
{
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 1; i <= n; i++) { cin >> a[i].x >> a[i].y; a[i].id = i; }
		for (int i = 1; i <= n; i++) { cin >> b[i].x >> b[i].y; b[i].id = i; }
		sort(a + 1, a + n + 1, cmp);
		sort(b + 1, b + n + 1, cmp2);
		cout << a[1].x + b[1].x << " " << a[1].y + b[1].y << endl;

	}
	return 0;
}