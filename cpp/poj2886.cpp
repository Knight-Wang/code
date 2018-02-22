#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 500005;

int antiprime[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040, 7560, 10080, 15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760, 277200, 332640, 498960, 554400};
int fac[] = {1, 2, 3, 4, 6, 8, 9, 10, 12, 16, 18, 20, 24, 30, 32, 36, 40, 48, 60, 64, 72, 80, 84, 90, 96, 100, 108, 120, 128, 144, 160, 168, 180, 192, 200, 216};

int tree[MAXN << 2], num[MAXN], n, k;
char name[MAXN][11];

void build(int num, int l, int r)
{
	if (l == r) { tree[num] = 1; return; }
	int m = l + r >> 1;
	build(num << 1, l, m);
	build(num << 1 | 1, m + 1, r);
	tree[num] = tree[num << 1] + tree[num << 1 | 1];
}

int kick(int num, int l, int r, int x)
{
	if (l == r) { tree[num] = 0; return l; }
	int m = l + r >> 1, tmp = tree[num << 1], ans = -1;
	if (tmp >= x) ans = kick(num << 1, l, m, x);
	else ans = kick(num << 1 | 1, m + 1, r, x - tmp);
	tree[num] = tree[num << 1] + tree[num << 1 | 1];
	return ans;
}

int main()
{
	while (scanf("%d %d", &n, &k) != EOF)
	{
		for (int i = 1; i <= n; i++) scanf("%s %d", name + i, num + i);
		build(1, 1, n);
		int now = k, out = -1, cnt = n;
		int tmp = lower_bound(antiprime, antiprime + 36, n) - antiprime;
		int w = antiprime[tmp] > n ? tmp - 1 : tmp;
		for (int i = 0; i < antiprime[w]; i++)
		{
			out = kick(1, 1, n, now);
			cnt--;
			if (!cnt) break;
			if (num[out] > 0) now = ((now + num[out] - 1) % cnt + cnt) % cnt;
			else now = ((now + num[out]) % cnt + cnt) % cnt;
			now = !now ? cnt : now;
		}
		printf("%s %d\n", name[out], fac[w]);
	}
	return 0;
}