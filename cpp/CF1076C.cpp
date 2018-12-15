#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t, n;
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n * n < 4 * n) { cout << "N" << endl; continue; }
		double tmp = sqrt(n * n - 4 * n);
		if ((double)n < tmp) { cout << "N" << endl; continue; }
		printf("Y %.10f %.10f\n", (n + tmp) / 2, (n - tmp) / 2);
	}
	return 0;
}