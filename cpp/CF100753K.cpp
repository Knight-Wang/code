#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

bool isPrime(ll x)
{
	for (ll i = 2; i * i <= x; i++)
	{
		if (x % i == 0) return false;
	}
	return x != 1;
}

int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	ll x;
	cin >> x;
	ll y = x, z = x;
	bool flag = true;
	while (x)
	{
		ll tmp = x % 10;
		if (tmp == 3 || tmp == 4 || tmp == 7)
		{
			flag = false;
			break;
		}
		x /= 10;
	}
	if (!flag) puts("no");
	else
	{
		ll ans = 0;
		while (y)
		{
			ll tmp = y % 10;
			if (tmp == 6) tmp = 9;
			else if (tmp == 9) tmp = 6;
			ans += tmp;
			y /= 10;
			if (y) ans *= 10;
		}
		if (isPrime(z) && isPrime(ans)) puts("yes");
		else puts("no");
	}
	return 0;
}