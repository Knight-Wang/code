#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int a[3][N];
int main()
{
    int n, q;
    while (cin >> n >> q)
    {
        for (int i = 1; i <= 2; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = 0;
            }
        }
        set<tuple<int, int, int>> st;
        for (int i = 0; i < q; i++)
        {
            int r, c;
            cin >> r >> c;
            int t = 3 - r;
            if (a[r][c] == 0)
            {
                a[r][c] = 1;
                if (c - 1 >= 1 && a[t][c - 1])
                {
                    st.insert(make_tuple(r, c, -1));
                    st.insert(make_tuple(t, c - 1, 1));
                }
                if (a[t][c])
                {
                    st.insert(make_tuple(r, c, 0));
                    st.insert(make_tuple(t, c, 0));
                }
                if (c + 1 <= n && a[t][c + 1])
                {
                    st.insert(make_tuple(r, c, 1));
                    st.insert(make_tuple(t, c + 1, -1));
                }
            }
            else
            {
                a[r][c] = 0;
                if (c - 1 >= 1 && a[t][c - 1])
                {
                    st.erase(make_tuple(r, c, -1));
                    st.erase(make_tuple(t, c - 1, 1));
                }
                if (a[t][c])
                {
                    st.erase(make_tuple(r, c, 0));
                    st.erase(make_tuple(t, c, 0));
                }
                if (c + 1 <= n && a[t][c + 1])
                {
                    st.erase(make_tuple(r, c, 1));
                    st.erase(make_tuple(t, c + 1, -1));
                }
            }
            cout << (!st.empty() ? "No" : "Yes") << endl;
        }
    }
    return 0;
}