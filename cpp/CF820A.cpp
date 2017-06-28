#include <iostream>
#include <cstdio>
using namespace std;
int c, v0, v1, a, l;
int main()
{
	cin >> c >> v0 >> v1 >> a >> l;
	int v = v0, now = v0, i = 1;
	while (now < c)
	{
		v = (v + a > v1 ? v1 : v + a);
		now += v - l;
		i++;
	}
	cout << i << endl;
	return 0;
}