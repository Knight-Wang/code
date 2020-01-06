#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    vector<char> c{'S', 'E', 'T'};
    while (cin >> n >> k)
    {
        int cnt = 0;
        string s;
        set<string> st;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            cin >> s; v.push_back(s); st.insert(s);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                string tmp = "";
                for (int p = 0; p < k; p++)
                {
                    if (v[i][p] == v[j][p])
                    {
                        tmp += v[i][p];
                    }
                    else
                    {
                        int l = 0;
                        for ( ; l < 3; l++)
                        {
                            if (c[l] != v[i][p] && c[l] != v[j][p]) break;
                        }
                        tmp += c[l];
                    }
                }
                st.erase(v[i]); st.erase(v[j]);
                if (st.count(tmp)) cnt++;
                st.insert(v[i]); st.insert(v[j]);
            }
        }
        cout << cnt / 3 << endl;
    }
    return 0;
}