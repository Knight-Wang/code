#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dfs(ll x, int s)
{
    if (x < 10)
    {
        if (s == 1) x--;
        return x == 0 ? 1 : x;
    }
    if (s == 1)
    {
        if (s % 10 == 0) return 9 * dfs(x / 10, 1);
        else
        {
            x--;
            if (x < 10) return x == 0 ? 1 : x;
            else return max(x % 10 * dfs(x / 10, 0), 9 * dfs(x / 10, 1));
        }
    }
    else return max(x % 10 * dfs(x / 10, 0), 9 * dfs(x / 10, 1));
}
int main()
{
    ll n;
    while (cin >> n)
    {
        cout << dfs(n, 0) << endl;
    }
    return 0;
}
