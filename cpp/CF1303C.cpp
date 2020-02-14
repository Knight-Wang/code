#include <bits/stdc++.h>
using namespace std;
int in[30], vis[30];
vector<int> G[30];
void dfs(int x)
{
    cout << char('a' + x);
    vis[x] = 1;
    for (int i = 0; i < G[x].size(); i++)
    {
        if (!vis[G[x][i]]) dfs(G[x][i]);
    }
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        memset(in, 0, sizeof in);
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 26; i++) G[i].clear();
        string s; cin >> s;
        int n = s.length();
        if (n == 1)
        {
            cout << "YES\n";
            for (int i = 0; i < 26; i++)
            {
                cout << char('a' + i);
            }
            cout << endl;
            continue;
        }
        map<char, set<char>> mp;
        set<char> st{s.begin(), s.end()};
        for (int i = 0; i < n - 1; i++)
        {
            if (!mp.count(s[i])) mp[s[i]] = set<char>();
            mp[s[i]].insert(s[i + 1]);
            if (!mp.count(s[i + 1])) mp[s[i + 1]] = set<char>();
            mp[s[i + 1]].insert(s[i]);
        }
        for (auto it: mp)
        {
            for (auto it1: it.second)
            {
                in[it1 - 'a']++;
                G[it.first - 'a'].push_back(it1 - 'a');
                G[it1 - 'a'].push_back(it.first - 'a');
            }
        }
        int c1 = 0, src = -1; bool flg = true;
        for (int i = 0; i < 26; i++)
        {
            if (in[i] == 0) continue;
            else if (in[i] == 1) { src = i; c1++; }
            else if (in[i] > 2) { flg = false; break; }
        }
        if (c1 != 2 || !flg) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        dfs(src);
        for (int i = 0; i < 26; i++)
        {
            char tmp = char('a' + i);
            if (!st.count(tmp)) cout << tmp;
        }
        cout << endl;
    }
    return 0;
}