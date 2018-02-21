#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 1005; 
int bit[MAXN][MAXN], x, n, t;

int lowbit(int x)
{
	return x & -x;
}

void add(int x, int y, int d)
{
	for (int i = x; i <= n; i += lowbit(i))
	{
		for (int j = y; j <= n; j += lowbit(j))
		{
			bit[i][j] += d;
		}
	}
}

int sum(int x, int y)
{
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
	{
		for (int j = y; j > 0; j -= lowbit(j))
		{
			ans += bit[i][j];
		}
	}
	return ans;
}

int main()
{
	scanf("%d", &x);
	char c; int x1, y1, x2, y2;
	while (x--)
	{
		memset(bit, 0, sizeof bit);
		scanf("%d %d", &n, &t);
		getchar();
		for (int i = 0; i < t; i++)
		{
			scanf("%c", &c);
			if (c == 'Q') 
			{
				scanf("%d %d", &x1, &y1);
				getchar();
				printf("%d\n", sum(x1, y1) & 1);
			}
			else
			{
				scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
				getchar();
				add(x1, y1, 1);
				add(x1, y2 + 1, -1);
				add(x2 + 1, y1, -1);
				add(x2 + 1, y2 + 1, 1);
			}
		}
		puts("");
	}
	return 0;
}
