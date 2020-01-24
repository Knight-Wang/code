#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        int x, y;
        vector<pair<int, int>> v{make_pair(0, 0)};
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            pair<int, int> tmp(x, y);
            v.push_back(tmp);
        }
        sort(v.begin(), v.end());
        bool flg = true;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v.size(); j++)
            {
                if (j == i) continue;
                if (v[j].first > v[i].first && v[j].second < v[i].second)
                {
                    flg = false; break;
                }
            }
        }
        if (!flg) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        string ans = "";
        for (int i = 0; i < v.size() - 1; i++)
        {
            for (int j = v[i].first; j < v[i + 1].first; j++) ans.push_back('R');
            for (int j = v[i].second; j < v[i + 1].second; j++) ans.push_back('U');
        }
        cout << ans << endl;
    }
    return 0;
}