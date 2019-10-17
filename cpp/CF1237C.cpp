#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n, x, y, z;
    while (cin >> n)
    {
        map<int, map<int, set<int>>> mp;
        map<tuple<int, int, int>, int> mp2;
        for (int i = 1; i <= n; i++)
        {
            cin >> x >> y >> z;
            mp2[make_tuple(x, y, z)] = i;
            if (!mp.count(x)) mp[x] = map<int, set<int>>();
            if (!mp[x].count(y)) mp[x][y] = set<int>();
            mp[x][y].insert(z);
        }
        for (auto it: mp)
        {
            for (auto it1: it.second)
            {
                if (it1.second.size() > 1)
                {
                    vector<tuple<int, int, int>> v;
                    for (auto it2: it1.second)
                    {
                        tuple<int, int, int> t = make_tuple(it.first, it1.first, it2);
                        v.push_back(t);
                        mp[it.first][it1.first].erase(it2);
                    }
                    if (v.size() % 2 == 1)
                    {
                        mp[get<0>(v.back())][get<1>(v.back())].insert(get<2>(v.back()));
                        v.pop_back();
                    }
                    for (int i = 0; i < v.size(); i += 2) cout << mp2[v[i]] << " " << mp2[v[i + 1]] << endl;
                }
            }
        }
        for (auto it: mp)
        {
            vector<tuple<int, int, int>> v;
            for (auto it1: it.second)
            {
                for (auto it2: it1.second)
                {
                    v.push_back(make_tuple(it.first, it1.first, it2));
                    mp[it.first][it1.first].erase(it2);
                }
            }
            if (v.size() % 2 == 1)
            {
                mp[get<0>(v.back())][get<1>(v.back())].insert(get<2>(v.back()));
                v.pop_back();
            }
            for (int i = 0; i < v.size(); i += 2) cout << mp2[v[i]] << " " << mp2[v[i + 1]] << endl; 
        }
        vector<tuple<int, int, int>> res;
        for (auto it: mp)
        {
            for (auto it1: it.second)
            {
                for (auto it2: it1.second)
                {
                    tuple<int, int, int> t = make_tuple(it.first, it1.first, it2);
                    res.push_back(t);
                }
            }
        }
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i += 2)
        {
            cout << mp2[res[i]] << " " << mp2[res[i + 1]] << endl;
        }
    }
    return 0;
}