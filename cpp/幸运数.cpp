#include <iostream>
using namespace std;
const int MAXN = 1000005;
int a[MAXN], nxt[MAXN];

int main()
{
	int l, r;
	cin >> l >> r;
	for (int i = 1; i <= r / 2; i++) { a[i] = 2 * i - 1; nxt[i] = i + 1; }
	nxt[r / 2] = -1;
	for (int k = 0; ; k++)
	{			
		int i = 1, tmp = nxt[1], last = 1;
		int tmp2 = tmp;
		for (int j = 1; j < k + 1; j++)	tmp2 = nxt[tmp2];
		int dx = a[tmp2];
		while (tmp != -1)
		{
			if ((i + 1) % dx == 0) nxt[last] = nxt[tmp];
			last = tmp;
			tmp = nxt[tmp];
			i++;
		}
		if (dx > i) break;
	}
	int tmp = 1, cnt = 0;
	while (tmp != -1) { if (a[tmp] > l && a[tmp] < r) cnt++; tmp = nxt[tmp]; }
	cout << cnt << endl;
	return 0;
}
