#include <bits/stdc++.h>
using namespace std;
 
queue<pair<char, int>> q[200005];
 
int main()
{
    int n; string s;
    while (cin >> n >> s)
    {
        for (int i = 0; i <= n; i++)
        {
            while (!q[i].empty()) q[i].pop();
        }
        int cur = 1;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            bool flg = false;
            while (j < cur)
            {
                if (q[j].empty() || s[i] >= q[j].back().first)
                {
                    q[j].push(make_pair(s[i], i)); flg = true; break;
                }
                j++;
            }
            if (!flg)
            {
                q[cur].push(make_pair(s[i], i));
                cur++;
            }
        }
        cout << cur << endl;
        multimap<char, pair<int, int>> mp;
        for (int i = 0; i < cur; i++)
        {
            mp.insert(make_pair(q[i].front().first, make_pair(q[i].front().second, i)));
            q[i].pop();
        }
        vector<pair<int, int>> v;
        while (!mp.empty())
        {
            pair<int, int> tmp = mp.begin()->second; 
            int id = tmp.second;
            v.push_back(tmp);
            mp.erase(mp.begin());
            if (!q[id].empty())
            {
                mp.insert(make_pair(q[id].front().first, make_pair(q[id].front().second, id)));
                q[id].pop();
            }
        }
        sort(v.begin(), v.end());
        for (auto it: v) cout << it.second + 1 << " ";
        cout << endl;
    }
    return 0;
}