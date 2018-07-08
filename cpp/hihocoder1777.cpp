#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

__int128 qpow(__int128 a, __int128 b, __int128 mod) 
{
    __int128 ret = 1LL;
    while (b) 
	{
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main() 
{
    LL n, k, P;
    scanf("%lld %lld %lld", &n, &k, &P);
    LL ans = qpow(k, n, P);
    printf("%lld\n", ans);
    return 0;
}