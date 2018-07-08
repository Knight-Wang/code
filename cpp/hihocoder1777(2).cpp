#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, k, p;
LL mul(LL a, LL b)
{
    LL ans = 0;
    while (b)
    {
        if (b & 1) ans = (ans + a) % p;
        a = (a + a) % p;
        b = b >> 1;
    }
    return ans;
}

LL Pow(LL a, LL b)
{
    LL result = 1;
    LL base = a % p;
    while (b)
    {
        if (b & 1) result = mul(result, base) % p;
        base = mul(base, base) % p;
        b = b >> 1;
    }
    return result;
}

int main()
{
	cin >> n >> k >> p;
	cout << Pow(k, n) << endl;
	return 0;
}