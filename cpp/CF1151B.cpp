#include <bits/stdc++.h>
using namespace std;

int a[505][505];
map<int, int> mp[505][10];
int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 10; j++) mp[i][j].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
                for (int k = 0; k < 10; k++)
                {
                    int msk = 1 << k;
                    int tmp = a[i][j] & msk;
                    if (tmp) mp[i][k][1] = j;
                    else mp[i][k][0] = j;
                }
            }
        }
        vector<int> ans;
        for (int k = 0; k < 10; k++)
        {
            int c1 = 0, c2 = 0;
            for (int i = 1; i <= n; i++)
            {
                if (mp[i][k].size() == 2) c2++;
                else if (mp[i][k].count(1)) c1++;
            }
            if (c1 & 1)
            {
                for (int i = 1; i <= n; i++)
                {
                    if (mp[i][k].size() == 2) ans.push_back(mp[i][k][0]);
                    else if (mp[i][k].count(1)) ans.push_back(mp[i][k][1]);
                    else ans.push_back(mp[i][k][0]);
                }
            }
            else if (c2)
            {
                bool flg = false;
                for (int i = 1; i <= n; i++)
                {
                    if (mp[i][k].size() == 2)
                    {
                        if (!flg) { ans.push_back(mp[i][k][1]); flg = !flg; }
                        else ans.push_back(mp[i][k][0]);
                    }
                    else if (mp[i][k].count(1)) ans.push_back(mp[i][k][1]);
                    else ans.push_back(mp[i][k][0]);
                }
            }
            if (!ans.empty()) break;
        }
        if (!ans.empty())
        {
            cout << "TAK" << endl;
            for (auto it: ans) cout << it << " ";
            cout << endl;
        }
        else cout << "NIE" << endl;
    }
    return 0;
}