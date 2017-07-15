#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

typedef long long ll;

int main()
{
	ll n, k, sum = 0, tmp;
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
	{
		cin >> tmp;
		ll x = 0;
		if (i >= min(k - 1, n - k) && i <= max(k - 1, n - k))
			x = min(k, n - k + 1);
		else
			x = min(i + 1, n - i);
		sum += x * tmp;
	}
	cout.precision(6);
	cout.setf(ios::fixed);
	cout << (double)sum / (n - k + 1) << endl;
	return 0;
}