#include <bits/stdc++.h>
using namespace std;
int check(vector<int>& v, set<pair<int, int>>& st)
{
    int res = 0;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= 6; i++)
    {
        for (int j = i; j <= 6; j++)
        {
            mp[make_pair(i, j)] = 0;
        }
    }
    for (auto it: st)
    {
        int a = v[it.first - 1], b = v[it.second - 1];
        pair<int, int> tmp(min(a, b), max(a, b));
        if (mp[tmp] == 0)
        {
            mp[tmp] = 1; res++;
        }
    }
    return res;
}
int main()
{
    int n, m, a, b;
    while (cin >> n >> m)
    {
        set<pair<int, int>> st;
        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            st.insert(make_pair(min(a, b), max(a, b)));
        }
        if (n <= 6) { cout << m << endl; continue; }
        vector<int> a{1, 1, 2, 3, 4, 5, 6};
        int maxn = 0;
        do
        {
            maxn = max(maxn, check(a, st));
        } while (next_permutation(a.begin(), a.end()));
        cout << maxn << endl;
    }
    return 0;
}