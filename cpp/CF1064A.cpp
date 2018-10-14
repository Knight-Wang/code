#include <iostream>
#include <algorithm>
using namespace std;
int a[3];
int main()
{
	while (cin >> a[0] >> a[1] >> a[2])
	{
		sort(a, a + 3);
		if (a[0] + a[1] > a[2]) cout << 0 << endl;
		else cout << -a[0] - a[1] + a[2] + 1 << endl;
	}
	return 0;
}
