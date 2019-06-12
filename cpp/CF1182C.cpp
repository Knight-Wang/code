#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; string s;
    set<char> st;
    st.insert('a'); st.insert('e'); st.insert('i'); st.insert('o'); st.insert('u'); 
    while (cin >> n)
    {
        unordered_map<char, unordered_map<int, vector<string>>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            char ch = 'a';
            int l = s.length();
            int cnt = 0;
            for (int j = 0; j < l; j++)
            {
                if (st.count(s[j])) { ch = s[j]; cnt++; }
            }
            if (!mp.count(ch)) mp[ch] = unordered_map<int, vector<string>>();
            if (!mp[ch].count(cnt)) mp[ch][cnt] = vector<string>();
            mp[ch][cnt].push_back(s);
        }
        int cnt = 0; unordered_map<int, vector<string>> mp2;
        vector<string> v1;
        for (auto it: mp)
        {
            for (auto it1: it.second)
            {
                int t = it1.second.size() / 2;
                cnt += t;
                for (int i = 0; i < 2 * t; i++) v1.push_back(mp[it.first][it1.first][i]);
                if (it1.second.size() - 2 * t > 0)
                {
                    if (!mp2.count(it1.first)) mp2[it1.first] = vector<string>();
                    for (int i = 2 * t; i < it1.second.size(); i++)
                        mp2[it1.first].push_back(mp[it.first][it1.first][i]);
                }
            }
        }
        int cnt2 = 0;
        for (auto it: mp2) cnt2 += it.second.size() / 2;
        int maxn = 0;
        for (int i = 0; i <= cnt; i++)
        {
            maxn = max(maxn, min(cnt2 + i, cnt - i));
        }
        cout << maxn << endl;
        vector<string> v2;
        for (auto it: mp2)
        {
            int t = it.second.size() / 2 * 2;
            for (int i = 0; i < t; i++)
                v2.push_back(mp2[it.first][i]);
        }
        for (int i = 2 * maxn; i < v1.size(); i++) v2.push_back(v1[i]);
        for (int i = 0; i < maxn; i++)
        {
            cout << v2[2 * i] << " " << v1[2 * i] << endl;
            cout << v2[2 * i + 1] << " " << v1[2 * i + 1] << endl;
        }
    }
    return 0;
}