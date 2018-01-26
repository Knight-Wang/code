#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
int v[MAXN], w[MAXN], ans[MAXN], n, k;
struct node
{
	int id;
	double x;
};
node buf[MAXN];
bool cmp(const node & a, const node & b)
{
	return a.x < b.x;
}
bool check(double x)
{
	for (int i = 0; i < n; i++) { buf[i].x = v[i] - x * w[i]; buf[i].id = i; }
	sort(buf, buf + n, cmp);
	double sum = 0;
	for (int i = n - 1; i > n - 1 - k; i--) sum += buf[i].x;
	if (sum >= 0)
	{
		for (int i = n - 1; i > n - 1 - k; i--) ans[n - 1 - i] = buf[i].id; return true;
	}
	return false;
}
int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) scanf("%d %d", &v[i], &w[i]);
	double l = 0, r = INF;
	for (int i = 0; i < 50; i++)
	{
		double m = (l + r) / 2;
		if (check(m)) l = m;
		else r = m;
	}
	for (int i = 0; i < k; i++) printf("%d ", ans[i] + 1);
	return 0;
}