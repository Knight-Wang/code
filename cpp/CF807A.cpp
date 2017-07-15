#include <iostream>
#include <cstdio>
using namespace std;

const int MAXN = 1005;
int n, a[MAXN], b[MAXN];

int main()
{
	cin >> n;
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i];
		if (a[i] != b[i])
			s = 1;
	}
	if (s == 1)
	{
		puts("rated");
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] < a[i + 1])
		{
			s = 2; break;
		}
	}
	if (s == 2) puts("unrated");
	else puts("maybe");
	return 0;
}