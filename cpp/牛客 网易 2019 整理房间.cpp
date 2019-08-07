#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
pii x[4], c[4];
pii rotate(pii& x, pii& c, int t)
{
    pii res(x);
    t %= 4;
    for (int i = 0; i < t; i++)
    {
        int tx = -res.second + c.first + c.second;
        int ty = res.first - c.first + c.second;
        res.first = tx; res.second = ty;
    }
    return res;
}
bool vertical(pii& a, pii& b)
{
    return a.first * b.first + a.second * b.second == 0;
}
int square(int x)
{
    return x * x;
}
int dis(pii& a, pii& b)
{
    return square(a.first - b.first) + square(a.second - b.second);
}
bool check(vector<pii>& v)
{
    sort(v.begin(), v.end());
    set<pii> st(v.begin(), v.end());
    if (st.size() != 4) return false;
    if (dis(v[0], v[1]) != dis(v[0], v[2])) return false;
    pii a(v[0].first - v[3].first, v[0].second - v[3].second);
    pii b(v[1].first - v[2].first, v[1].second - v[2].second);
    return vertical(a, b);
}
int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        for (int i = 0; i < 4; i++)
        {
            cin >> x[i].first >> x[i].second >> c[i].first >> c[i].second;
        }
        int minn = INF;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    for (int l = 0; l < 4; l++)
                    {
                        vector<pii> v;
                        v.push_back(rotate(x[0], c[0], i));
                        v.push_back(rotate(x[1], c[1], j));
                        v.push_back(rotate(x[2], c[2], k));
                        v.push_back(rotate(x[3], c[3], l));
                        if (check(v)) minn = min(minn, i + j + k + l);
                    }
                }
            }
        }
        cout << (minn == INF ? -1 : minn) << endl;
    }
    return 0;
}