#include <bits/stdc++.h>
using namespace std;

struct Line
{
    map<int, int> mapp;
    int find(int x)
    {
        if (!mapp.size()) return -1;
        auto it = mapp.lower_bound(x);
        if (it != mapp.end() && it->first == x) return x;
        if (it == mapp.begin()) return -1;
        it--;
        if (it->second >= x) return it->first;
        return -1;
    }
    void add(int x)
    {
        if (find(x) != -1) return;
        int pre = find(x - 1);
        int suf = find(x + 1);
        if (pre == -1 && suf == -1) mapp[x] = x;
        else if (pre != -1 && suf == -1) mapp[pre] = x;
        else if (pre == -1 && suf != -1) { mapp[x] = mapp[suf]; mapp.erase(suf); }
        else { mapp[pre] = mapp[suf]; mapp.erase(suf); }
    }
};
unordered_map<int, Line> rows;
unordered_map<int, Line> cols;
unordered_map<char, int> dx, dy;
int k, n, m, x, y;
string ins;

int main()
{
    ios::sync_with_stdio(false);
    dx['N'] = -1, dx['S'] = 1, dx['W'] = 0, dx['E'] = 0;
    dy['N'] = 0, dy['S'] = 0, dy['W'] = -1, dy['E'] = 1;
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cin >> k >> n >> m >> x >> y;
        cin >> ins;
        rows.clear(); cols.clear();
        for (auto c : ins)
        {
            rows[x].add(y); cols[y].add(x);
            x += dx[c]; y += dy[c];
            if (c == 'W' || c == 'E')
            {
                int tmp = rows[x].find(y);
                if (tmp != -1)
                {
                    if (c == 'E') y = rows[x].mapp[tmp] + 1;
                    else y = tmp - 1;
                }
            }
            else
            {
                int tmp = cols[y].find(x);
                if (tmp != -1)
                {
                    if (c == 'S') x = cols[y].mapp[tmp] + 1;
                    else x = tmp - 1;
                }
            }
        }
        cout << "Case #" << t << ": " << x << " " << y << endl;
    }
    return 0;
}