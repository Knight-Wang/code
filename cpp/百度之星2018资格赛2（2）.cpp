#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[N], n, q;
int sum[N][30];

int main()
{
    ios::sync_with_stdio(false);
    int T, l, r;
    string s;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        cin >> n >> q;
        cin >> s;
        for (int i = 0; i < n; i++) a[i + 1] = s[i] - 'A';
        memset(sum, 0, sizeof sum);
        for (int j = 1; j <= n; j++)
        {
            int tmp = s[j - 1] - 'A';
            for (int k = 0; k < 26; k++)
                sum[j][k] = sum[j - 1][k];
            sum[j][tmp]++;
        }
        cout << "Case #" << t + 1 << ":" << endl;
        for (int i = 0; i < q; i++) 
        {
            cin >> l >> r;
            for (int j = 0; j < 26; j++)
            {
                int tmp = sum[r][j] - sum[l - 1][j];
                if (tmp != 0) { cout << tmp << endl; break; }
            }
        }
    }
    return 0;
}