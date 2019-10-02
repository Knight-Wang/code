#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k, x;
    while (cin >> n >> k)
    {
        deque<int> d;
        set<int> st;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            if (st.count(x)) continue;
            d.push_front(x); st.insert(x);
            if (d.size() > k)
            {
                st.erase(d.back());
                d.pop_back();
            }
        }
        cout << d.size() << endl;
        for (auto it: d) cout << it << " ";
        cout << endl;
    }
    return 0;
}