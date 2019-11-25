#include <bits/stdc++.h>
using namespace std;
bool cmp1(pair<int, int>& a, pair<int, int>& b)
{
    return a.second < b.second;
}
bool cmp2(pair<int, int>& a, pair<int, int>& b)
{
    return a.first < b.first;
}
int main()
{
    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        int l, r;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> l >> r;
            v.push_back(make_pair(l, r));
        }
        if (n == 1) { cout << 0 << endl; continue; }
        sort(v.begin(), v.end(), cmp1);
        int x = v[0].second;
        sort(v.begin(), v.end(), cmp2);
        int y = v.back().first;
        cout << max(y - x, 0) << endl;
    }
    return 0;
}