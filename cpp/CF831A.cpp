#include <iostream>
#include <cstdio>
using namespace std;
int a[105];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	if (n == 1) { puts("YES"); return 0;}
	int i = 1;
	while (i < n && a[i] > a[i - 1]) i++;
	while (i < n && a[i] == a[i - 1]) i++;
	while (i < n && a[i] < a[i - 1]) i++;
	if (i != n) { puts("NO"); return 0; }
	puts("YES");
	return 0;
}