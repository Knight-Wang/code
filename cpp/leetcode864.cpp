class Solution
{
public:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int shortestPathAllKeys(vector<string>& grid)
    {
        if (grid.empty()) return -1;
        using tiii = tuple<int, int, int>;
        queue<tiii> q;
        map<tiii, int> mp;
        int k = 0;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '@')
                {
                    q.push(make_tuple(0, i, j));
                    mp[make_tuple(0, i, j)] = 0;
                }
                else if (grid[i][j] >= 'A' && grid[i][j] <= 'F')
                {
                    k = max(k, grid[i][j] - 'A' + 1);
                }
            }
        }
        int msk = (1 << k) - 1;
        while (!q.empty())
        {
            tiii tmp = q.front(); q.pop();
            int s = get<0>(tmp), x = get<1>(tmp), y = get<2>(tmp);
            if ((s & msk) == msk) return mp[tmp];
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '#') continue;
                if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F')
                {
                    int p = 1 << (grid[nx][ny] - 'A');
                    if (!(s & p)) continue;
                }
                int ns = s;
                if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f')
                {
                    int p = 1 << (grid[nx][ny] - 'a');
                    ns |= p;
                }
                tiii nxt(ns, nx, ny);
                if (mp.count(nxt)) continue;
                q.push(nxt);
                mp[nxt] = mp[tmp] + 1;
            }
        }
        return -1;
    }
};