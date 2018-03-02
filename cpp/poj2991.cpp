#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN = 10005;
const double PI = acos(-1.0);

int a[MAXN], d[MAXN], n, c;
struct node
{
	double x, y;
	int lazy;
};
node tree[MAXN << 2];
double trans(int d) { return (double)d * PI / 180.0; }
void rotate(double & x, double & y, int dx)
{
	double tx = x * cos(trans(dx)) - y * sin(trans(dx));
	double ty = y * cos(trans(dx)) + x * sin(trans(dx));
	x = tx; y = ty;
}
void pushdown(int num)
{
	if (!tree[num].lazy) return;
	int tmp = tree[num].lazy;
	rotate(tree[num << 1].x, tree[num << 1].y, tmp);
	rotate(tree[num << 1 | 1].x, tree[num << 1 | 1].y, tmp);
	tree[num << 1].lazy += tmp;
	tree[num << 1 | 1].lazy += tmp;
	tree[num].lazy = 0;
}
void pushup(int num)
{
	tree[num].x = tree[num << 1].x + tree[num << 1 | 1].x;
	tree[num].y = tree[num << 1].y + tree[num << 1 | 1].y;
}
void build(int num, int l, int r)
{
	if (l == r) { tree[num].y = a[r]; return; }
	int m = l + r >> 1;
	build(num << 1, l, m);
	build(num << 1 | 1, m + 1, r);
	pushup(num);
}
void update(int num, int l, int r, int x, int y, int dx)
{
	if (x <= l && y >= r) 
	{ 
		rotate(tree[num].x, tree[num].y, dx);
		tree[num].lazy += dx;
		return;
	}
	int m = l + r >> 1;
	pushdown(num);
	if (x <= m) update(num << 1, l, m, x, y, dx);
	if (y >= m + 1) update(num << 1 | 1, m + 1, r, x, y, dx);
	pushup(num);
}

int main()
{
	while (scanf("%d %d", &n, &c) != EOF)
	{
		for (int i = 1; i <= n * 4; i++) { tree[i].x = tree[i].y = 0; tree[i].lazy = 0; }
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for (int i = 1; i < n; i++) d[i] = 180;
		build(1, 1, n);
		int x, y;
		for (int i = 0; i < c; i++)
		{
			scanf("%d %d", &x, &y);
			int dx = y - d[x];
			d[x] = y;
			update(1, 1, n, x + 1, n, dx);
			printf("%.2f %.2f\n", tree[1].x, tree[1].y);
		}
		puts("");
	}
	return 0;
}