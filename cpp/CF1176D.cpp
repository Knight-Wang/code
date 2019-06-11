#include <bits/stdc++.h>
using namespace std;
const int N = 2750131, M = 199999;

bool is_prime[N + 1];
int prime[M];

void init()
{
    int p = 0;
    for (int i = 0; i <= N; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= N; i++)
    {
        if (is_prime[i])
        {
            prime[p++] = i;
            for (int j = 2 * i; j <= N; j += i) is_prime[j] = false;
        }
    }
}
int main()
{
    int n, x;
    init();
    while (cin >> n)
    {
        vector<int> ans;
        map<int, int> mp;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> x;
            if (!mp.count(x)) mp[x] = 0;
            mp[x]++;
        }
        for (auto it = mp.rbegin(); it != mp.rend(); it++)
        {
            int k = it->first, cnt = it->second;
            if (is_prime[k])
            {
                int t = lower_bound(prime, prime + M, k) - prime + 1;
                mp[t] -= cnt;
                for (int j = 0; j < cnt; j++) ans.push_back(t);
            }
            else
            {
                int j = 2;
                for ( ; j * j <= k; j++)
                {
                    if (k % j == 0) break;
                }
                mp[k / j] -= cnt;
                for (int j = 0; j < cnt; j++) ans.push_back(k);
            }
        }
        for (auto it: ans) cout << it << " ";
        cout << endl; 
    }
    return 0;
}