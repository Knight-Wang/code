#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		cout << n - ((n + 1) >> 1) + 1 << endl;
	}
	return 0;
}