#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, S;
	while (cin >> n >> S)
	{
		if (n >= S) cout << 1 << endl;
		else cout << (S + n - 1) / n << endl;
	}
	return 0;
}