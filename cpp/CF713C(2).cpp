#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, x;
    while (cin >> n)
    {
        ll ans = 0;
        priority_queue<int> pq;
        for (int i = 1; i <= n; i++)
        {
            cin >> x;
            x -= i;
            pq.push(x);
            if (x < pq.top())
            {
                ans += (ll)pq.top() - x;
                pq.pop();
                pq.push(x);
            }
        }
        cout << ans << endl;
    }
    return 0;
}