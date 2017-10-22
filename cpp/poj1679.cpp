#include <bits/stdc++.h>
using namespace std;
struct eg
{
	int a, b, w;
};
eg es[23333];
int fa[233];
int find(int now)
{
	if (fa[now] == now) return now;
	return fa[now] = find(fa[now]);
}
bool uni0n(int a, int b)
{
	a = find(a), b = find(b);
	if (a != b) { fa[b] = a; return true; }
	return false;
}
bool same(int a, int b)
{
	return find(a) == find(b);
}
bool compare(const eg& x, const eg& y)
{
	return x.w <= y.w;
}
int main()
{
	int T, N, M;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d %d", &N, &M);
		for (int i = 1; i <= N; i++) fa[i] = i;
		for (int i = 1; i <= M; i++) scanf("%d %d %d", &es[i].a, &es[i].b, &es[i].w);
		sort(es + 1, es + M + 1, compare);
		int i = 1, cnt = N, sum = 0;
		bool flg = true;
		while (i <= M)
		{			
			if (!flg || cnt == 1) break;
			vector<int> v;
			int j = i;
			while (j <= M && (j == i || es[j].w == es[j - 1].w))
			{
				if (!same(es[j].a, es[j].b)) v.push_back(j);
				j++;
			}
			for (int k = 0; k < (int)v.size(); k++)
			{
				if (!uni0n(es[v[k]].a, es[v[k]].b))
				{
					flg = false; break;
				}
				else 
				{
					cnt--; sum += es[v[k]].w;
				}
			}
			i = j;
		}
		if (flg) printf("%d\n", sum);
		else puts("Not Unique!");
	} 
	return 0;
}