#include <bits/stdc++.h>
using namespace std;

int ans[100005];
int main()
{
    int n;
    while (cin >> n)
    {
        memset(ans, 0, sizeof ans);
        int cur = 1;
        for (int i = 2; i <= n; i++)
        {
            if (ans[i]) continue;
            for (int j = i; j <= n; j += i)
                if (!ans[j]) ans[j] = cur;
            cur++;
        }
        for (int i = 2; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}