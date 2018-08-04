#include<bits/stdc++.h>
using namespace std;
int num[1005];
int main()
{
    ios::sync_with_stdio(false);
    int T, n, m, k;
    string s;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> m >> k;
        unordered_map<int, int> mp;
        int cnt = 0;
        for (int i = 0; i < n; i++) 
        {
            cin >> s;
            int tmp = 0;
            for (int j = 0; j < m; j++)
            {
                if (s[j] == 'A') tmp++;
                if (j != m - 1) tmp <<= 1;
            }
            num[i] = tmp;
        }
        for (int i = 1; i < 1 << m; i++)
        {
            mp.clear();
            for (int j = 0; j < n; j++)
            {
                int k = num[j] & i;
                if (!mp.count(k)) mp[k] = 0;
                mp[k]++;
            }
            long long ans = 0;
            vector<int> v;
            for (auto it: mp) v.push_back(it.second);
            int l = v.size();
            vector<int> sum(l, 0);
            sum[l - 1] = v[l - 1];
            for (int j = l - 2; j >= 0; j--)
            {
                sum[j] = sum[j + 1] + v[j];
            }
            for (int j = 0; j < l - 1; j++)
            {
                ans += (long long)v[j] * sum[j + 1];
            }
            cnt += ans >= k;
        }
        cout << "Case #" << t + 1 << ": " << cnt << endl;
    }
    return 0;
}