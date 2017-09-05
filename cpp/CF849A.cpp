#include <bits/stdc++.h>
using namespace std;
int a[105], n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (a[0] & 1 && a[n - 1] & 1 && n & 1) puts("Yes");
	else puts("No");
	return 0;
}