#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 500005;
ll a[N], l[N], r[N];
int main()
{
    int n;
    while (cin >> n)
    {
        stack<int> st;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.empty()) l[i] = i * a[i];
            else l[i] = l[st.top()] + (i - st.top()) * a[i];
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n; i >= 1; i--)
        {
            while (!st.empty() && a[st.top()] >= a[i]) st.pop();
            if (st.empty()) r[i] = (n - i + 1) * a[i];
            else r[i] = r[st.top()] + (st.top() - i) * a[i];
            st.push(i);
        }
        ll res = 0, id = 0;
        for (int i = 1; i <= n; i++)
        {
            ll tmp = l[i] + r[i] - a[i];
            if (tmp > res) { res = tmp; id = i; }
        }
        for (int i = id - 1; i >= 1; i--) a[i] = min(a[i], a[i + 1]);
        for (int i = id + 1; i <= n; i++) a[i] = min(a[i], a[i - 1]);
        for (int i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}