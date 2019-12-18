#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<string, int>& a, pair<string, int>& b)
{
    return a.first < b.first;
}
bool cmp2(pair<string, int>& a, pair<string, int>& b)
{
    return a.second < b.second;
}
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        vector<pair<string, int>> v(n);
        set<char> st;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i].first; v[i].second = i;
            st.insert(v[i].first[0]);
        }
        set<char> st2;
        for (char i = '0'; i <= '9'; i++)
        {
            if (st.count(i)) continue;
            st2.insert(i);
        }
        sort(v.begin(), v.end(), cmp);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j + 1 < n && v[j + 1].first == v[j].first) j++;
            for (int k = i + 1; k <= j; k++)
            {
                char tmp = *st2.begin();
                v[k].first[0] = tmp;
                st2.erase(st2.begin());
                cnt++;
            }
            i = j;
        }
        sort(v.begin(), v.end(), cmp2);
        cout << cnt << endl;
        for (auto it: v) cout << it.first << endl;
    }
    return 0;
}