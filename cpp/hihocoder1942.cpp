#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int a[N];
ll solve(int n)
{
    ll ans = 0;
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
    {
        pq.push(a[i]);
        if (a[i] < pq.top())
        {
            ans += (ll)pq.top() - a[i];
            pq.pop();
            pq.push(a[i]);
        }
    }
    return ans;
}
int main()
{
    int n, x;
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ans = solve(n);
        reverse(a + 1, a + n + 1);
        ans = min(ans, solve(n));
        cout << ans << endl;
    }
    return 0;
}