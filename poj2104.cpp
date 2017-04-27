// poj2104.cpp : 定义控制台应用程序的入口点。
// 划分树

//#include "stdafx.h"
#include <cstdio>  
#include <algorithm>  
using namespace std;
const int MAXN = 100000 + 1;
const int DEEP = 18;
typedef struct
{
	int num[MAXN];
	int cnt[MAXN];
}PartitionTree;
PartitionTree tree[DEEP];
int sorted[MAXN];

void build(int deep, int lft, int rht)
{
	if (lft == rht)
		return;
	int mid = (lft + rht) >> 1;
	int key = sorted[mid];
	int scnt = mid - lft + 1;
	for (int i = lft; i <= rht; i++)
	{
		if (tree[deep].num[i] < key)
			scnt--;
	}
	int p = lft - 1, r = mid;
	for (int i = lft, cnt = 0; i <= rht; i++)
	{
		int num = tree[deep].num[i];
		if (num < key || (num == key && scnt))
		{
			if (num == key)
				scnt--;
			cnt++;
			tree[deep + 1].num[++p] = num;
		}
		else
			tree[deep + 1].num[++r] = num;
		tree[deep].cnt[i] = cnt;
	}
	build(deep + 1, lft, mid);
	build(deep + 1, mid + 1, rht);
}

int query(int deep, int lft, int rht, int qlft, int qrht, int k)
{
	if (lft == rht)
		return tree[deep].num[lft];
	int mid = (lft + rht) >> 1;
	int left = 0, sum_in_left = tree[deep].cnt[qrht];
	if (lft != qlft)
	{
		left = tree[deep].cnt[qlft - 1];
		sum_in_left -= left;
	}
	if (sum_in_left >= k)
	{
		int new_qlft = lft + left;
		int new_qrht = new_qlft + sum_in_left - 1;
		return query(deep + 1, lft, mid, new_qlft, new_qrht, k);
	}
	else
	{
		int a = qlft - lft - left;
		int b = qrht - qlft - sum_in_left;
		int new_qlft = mid + 1 + a;
		int new_qrht = new_qlft + b;
		return query(deep + 1, mid + 1, rht, new_qlft, new_qrht, k - sum_in_left);
	}
}

int main()
{
	int n, m, qlft, qrht, k;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sorted[i]);
		tree[0].num[i] = sorted[i];
	}
	sort(sorted + 1, sorted + 1 + n);
	build(0, 1, n);
	while (m--)
	{
		scanf("%d %d %d", &qlft, &qrht, &k);
		printf("%d\n", query(0, 1, n, qlft, qrht, k));
	}
	//system("pause");
	return 0;
}