#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int in[N];
int main()
{
    int n, a, b;
    double s;
    while (cin >> n >> s)
    {
        memset(in, 0, sizeof in);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a >> b;
            in[a]++; in[b]++;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (in[i] == 1) cnt++;
        }
        cout << setprecision(15) << s / cnt * 2 << endl;
    }
    return 0;
}