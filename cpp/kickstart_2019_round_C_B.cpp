#include <bits/stdc++.h>
using namespace std;
const int N = 305;
int a[N][N], b[N][N];
int main()
{
    int T, r, c, k;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(b, 0x3f, sizeof b);
        cin >> r >> c >> k;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                cin >> a[i][j];
        for (int i = 0; i < r; i++)
        {
            map<int, int> mp;
            int f = 0, s = 0;
            while (f < c)
            {
                while (f < c)
                {
                    if (!mp.count(a[i][f])) mp[a[i][f]] = 0;
                    mp[a[i][f]]++;
                    if (mp.rbegin()->first - mp.begin()->first > k) break;
                    b[i][f] = f - s + 1;
                    f++;
                }
                while (s < f && mp.rbegin()->first - mp.begin()->first > k)
                {
                    if (mp[a[i][s]] == 1) mp.erase(a[i][s]);
                    else mp[a[i][s]]--;
                    s++;
                }
                b[i][f] = f - s + 1;
                f++;
            }
        }
        int ans = 0;
        for (int j = 0; j < c; j++)
        {
            stack<pair<int, int>> sta;
            vector<int> pre;
            for (int i = 0; i < r; i++)
            {
                while (sta.size() && sta.top().first >= b[i][j]) sta.pop();
                if (!sta.empty()) pre.push_back(sta.top().second + 1);
                else pre.push_back(0);
                sta.push(make_pair(b[i][j], i)); 
            }
            while (sta.size()) sta.pop();
            for (int i = r - 1; i >= 0; i--)
            {
                while (sta.size() && sta.top().first >= b[i][j]) sta.pop();
                if (!sta.empty()) ans = max(ans, (sta.top().second - pre[i]) * b[i][j]);
                else ans = max(ans, b[i][j] * (r - pre[i]));
                sta.push(make_pair(b[i][j], i)); 
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}