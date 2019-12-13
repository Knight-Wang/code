#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k; string s; char c;
    while (cin >> n >> k)
    {
        cin >> s;
        set<char> st;
        for (int i = 0; i < k; i++) { cin >> c; st.insert(c); }
        long long res = 0;
        for (int i = 0; i < n; i++)
        {
            int j = i;
            while (j < n && st.count(s[j])) j++;
            res += ((long long)j - i) * (j - i + 1) / 2;
            i = j;
        }
        cout << res << endl;
    }
    return 0;
}