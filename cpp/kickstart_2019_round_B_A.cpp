#include <bits/stdc++.h>
using namespace std;

int cnt[100005][30];

int main()
{
    int T, n, q, l, r; string s;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        memset(cnt, 0, sizeof cnt);
        cin >> n >> q >> s;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 25; j++) cnt[i + 1][j] = cnt[i][j];
            cnt[i + 1][s[i] - 'A'] = cnt[i][s[i] - 'A'] + 1;
        }
        int ans = 0;
        for (int i = 0; i < q; i++)
        {
            cin >> l >> r;
            int x = 0, s = r - l + 1;
            bool flg = true;
            for (int j = 0; j <= 25; j++)
            {
                int t = cnt[r][j] - cnt[l - 1][j];
                if (t & 1) x++;
                if ((s % 2 == 1 && x > 1) || (s % 2 == 0 && x > 0))
                {
                    flg = false;
                }
            }
            if (flg) ans++;
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}