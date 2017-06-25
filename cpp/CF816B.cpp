#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 200005;
int a[MAXN], n, k, q;

int main()
{
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		a[l]++; a[r + 1]--;
	}
	for (int i = 1; i < MAXN; i++) a[i] += a[i - 1];
	for (int i = 1; i < MAXN; i++) 
		if (a[i] >= k) a[i] = 1;
		else a[i] = 0;
	for (int i = 1; i < MAXN; i++) a[i] += a[i - 1];
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%d\n", a[r] - a[l - 1]);
	}
	return 0;
}