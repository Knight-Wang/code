#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1505;

int n, q, m, ans[30][MAXN];
string s;
char c;

int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	cin >> n >> s;
	for (int k = 0; k < 26; k++)
	{
		char tmp = 'a' + k;
		for (int i = 0; i < n; i++)
		{
			int cnt = 0;
			for (int j = i; j < n; j++)
			{
				if (s[j] != tmp) cnt++;
				ans[k][cnt] = max(ans[k][cnt], j - i + 1);
			}
		}
		for (int i = 1; i < MAXN; i++)
			ans[k][i] = max(ans[k][i], ans[k][i - 1]);
	}
	cin >> q;
	for (int i = 0; i < q; i++)
	{
		scanf("%d %c", &m, &c);
		printf("%d\n", ans[c - 'a'][m]);
	}
}