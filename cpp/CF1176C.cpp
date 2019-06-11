#include <bits/stdc++.h>
using namespace std;

int cnt[7];
int main()
{
    map<int, int> mp = {{4, 1}, {8, 2}, {15, 3}, {16, 4}, {23, 5}, {42, 6}};
    int n, x;
    while (cin >> n)
    {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            x = mp[x];
            if (x == 1) { cnt[x]++; continue; }
            if (cnt[x - 1])
            {
                cnt[x - 1]--;
                cnt[x]++;
            }
        }
        cout << n - 6 * cnt[6] << endl;
    }
    return 0;
}