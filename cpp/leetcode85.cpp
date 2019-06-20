#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int n = matrix.size(); if (n == 0) return 0;
        int m = matrix[0].size(); if (m == 0) return 0;
        int ans = 0;
        vector<int> h(m, 0), l(m, 0), r(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                h[j] = (matrix[i][j] == '0' ? 0 : h[j] + 1);
            }
            stack<int> s;
            for (int j = 0; j < m; j++)
            {
                while (!s.empty() && h[s.top()] >= h[j]) s.pop();
                l[j] = (s.empty() ? 0 : s.top() + 1);
                s.push(j);
            }
            while (!s.empty()) s.pop();
            for (int j = m - 1; j >= 0; j--)
            {
                while (!s.empty() && h[s.top()] >= h[j]) s.pop();
                r[j] = (s.empty() ? m - 1 : s.top() - 1);
                s.push(j);
            }
            for (int j = 0; j < m; j++)
            {
                ans = max(ans, (r[j] - l[j] + 1) * h[j]);
            }
        }
        return ans;
    }
};
int main()
{
    char a[][5] = {{'1','0','1','0','0'},
                  {'1','0','1','1','1'},
                  {'1','1','1','1','1'},
                  {'1','0','0','1','0'}};
    // char a[][4] = {{'1','1','1','1'},
    //               {'1','1','1','1'},
    //               {'1','1','1','1'}};
    vector<vector<char>> v;
    for (int i = 0; i < 4; i++)
    {
        v.push_back(vector<char>(a[i], a[i] + 5));
    }
    cout << Solution().maximalRectangle(v) << endl;
    return 0;
}