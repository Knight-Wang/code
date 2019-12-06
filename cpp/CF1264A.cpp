#include <bits/stdc++.h>
using namespace std;
int a[400005];
int main()
{
    int t, n;
    while (cin >> t)
    {
        while (t--)
        {
            cin >> n;
            for (int i = 0; i < n; i++) cin >> a[i];
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                int j = i;
                while (j + 1 < n && a[j + 1] == a[j]) j++;
                v.push_back(j - i + 1);
                i = j;
            }
            int m = v.size();
            int sum = 0, i = 0;
            while (i < m && (sum + v[i]) * 2 <= n) { sum += v[i]; i++; }
            int p = i - 1;
            if (p < 0) { cout << "0 0 0\n"; continue; }
            vector<int> s(p + 1, 0);
            s[0] = v[0];
            for (int i = 1; i <= p; i++) s[i] = s[i - 1] + v[i];
            int res_g = 0, res_s = 0, res_b = 0;
            for (int i = 0; i <= p - 2; i++)
            {
                int tmp_g = s[i];
                int tmp_s = lower_bound(s.begin() + i + 1, s.end(), tmp_g * 2 + 1) - s.begin();
                if (tmp_s >= p) continue;
                if (s[p] - s[tmp_s] <= tmp_g) continue;
                res_g = s[i]; res_s = s[tmp_s] - s[i]; res_b = s[p] - s[tmp_s];
            }
            cout << res_g << " " << res_s << " " << res_b << endl;
        }
    }
    return 0;
}