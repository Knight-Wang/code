#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int a, b;
	cin >> a >> b;
	int ans = 1;
	for (int i = 2; i <= min(a, b); i++)
		ans *= i;
	cout << ans << endl;
	return 0;
}