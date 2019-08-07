#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int C[201][201];
void init()
{
    C[0][0] = C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 200; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= 200; j++)
        {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= INF) C[i][j] = INF;
        }
 
    }
}
int main()
{
    int n, m, k;
    init();
    while (cin >> n >> m >> k)
    {
        if (k > C[n + m][n]) { cout << -1 << endl; continue; }
        string ans = "";
        int a = n, b = m;
        while (ans.length() < a + b)
        {
            int x = C[n - 1 + m][n - 1];
            if (k <= x)
            {
                ans += 'a'; n--;
            }
            else
            {
                ans += 'z'; m--; k -= x;
            }
        }
        cout << ans << endl;
    }
    return 0;
}