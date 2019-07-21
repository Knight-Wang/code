#include <bits/stdc++.h>
using namespace std;
 
int Prime[2005];
bool isPrime[2005];
 
int SetPrime(int n)
{
    int len = 0;
    memset(isPrime, true, sizeof isPrime);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            Prime[len++] = i;
            for (int j = 2 * i; j <= n; j += i) isPrime[j] = false;
        }
    }
    return len;
}
 
int main()
{
    int cnt = SetPrime(2000);
    int n;
    while (cin >> n)
    {
        vector<pair<int, int>> v;
        for (int i = 1; i < n; i++) v.push_back(make_pair(i, i + 1));
        v.push_back(make_pair(1, n));
        int id = lower_bound(Prime, Prime + cnt, n) - Prime;
        int p = Prime[id], x = 2, y = n;
        while (n < p)
        {
            v.push_back(make_pair(x, y));
            x++; y--;
            n++;
        }
        cout << v.size() << endl;
        for (auto it: v) cout << it.first << " " << it.second << endl;
    }
    return 0;
}