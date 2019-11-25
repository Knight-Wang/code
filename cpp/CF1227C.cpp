#include <bits/stdc++.h>
using namespace std;
int main()
{
    int T; cin >> T;
    while (T--)
    {
        int n, k; string s; cin >> n >> k >> s;
        vector<pair<int, int>> res;
        for (int i = 0; i < n / 2; i++)
        {
            if (s[i] == '(') continue;
            int j = i + 1;
            while (j < n && s[j] != '(') j++;
            res.push_back(make_pair(i, j));
            reverse(s.begin() + i, s.begin() + j + 1);
        }
        for (int i = 0; i < k - 1; i++)
        {
            int cur = 2 * i + 1;
            int j = cur + 1;
            while (j < n && s[j] != ')') j++;
            res.push_back(make_pair(cur, j));
            reverse(s.begin() + cur, s.begin() + j + 1);
        }
        cout << res.size() << endl;
        for (auto it: res)
        {
            cout << it.first + 1 << " " << it.second + 1 << endl;
        }
    }
    return 0;
}