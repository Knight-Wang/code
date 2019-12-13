#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int d[] = {-1, 0, 1};
ll work(ll a, ll b, ll c)
{
    return abs(a - b) + abs(b - c) + abs(a - c);
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll ans = INF;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    ans = min(ans, work(a + d[i], b + d[j], c + d[k]));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}