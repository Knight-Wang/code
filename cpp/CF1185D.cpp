#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
pair<ll, int> a[200005];
int n;
bool check(int x, int & ans)
{
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        ll d = a[i + 1].first - a[i].first;
        if (d != x)
        {
            if (i == 1)
            {
                cnt++;
                if (d + a[3].first - a[2].first == x)
                {
                    ans = a[2].second; i++;
                }
                else ans = a[1].second;
            }
            else if (i == n - 1) { cnt++; ans = a[n].second; }
            else
            {
                if (d + a[i + 2].first - a[i + 1].first == x)
                {
                    cnt++; ans = a[i + 1].second; i++;
                }
                else return false;
            }
        }
    }
    return cnt <= 1;
}
int main()
{
    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) { cin >> a[i].first; a[i].second = i; }
        if (n <= 3) { cout << 1 << endl; continue; }
        sort(a + 1, a + n + 1);
        set<int> st;
        for (int i = 1; i < n; i++) st.insert(a[i + 1].first - a[i].first);
        int m = st.size();
        if (m >= 4) cout << -1 << endl;
        else if (m == 1) cout << a[1].second << endl;
        else
        {
            int ans = -1; bool flg = false;
            for (auto it: st)
            {
                if (check(it, ans)) { flg = true; break; }
            }
            cout << (flg ? ans : -1) << endl;
        }
    }
    return 0;
}