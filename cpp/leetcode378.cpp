#include <bits/stdc++.h>
using namespace std;
/*
// Solution 1
class Solution 
{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> q;
        int n = matrix.size();
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) q.push(make_pair(matrix[i][v[i]], i));
        pair<int, int> tmp;
        for (int i = 0; i < k; i++)
        {
            tmp = q.top(); q.pop();
            int id = tmp.second;
            while (v[id] == n) 
            {
                tmp = q.top();
                q.pop();
                id = tmp.second;
            }
            assert(v[id] != n);
            v[id]++;
            q.push(make_pair(matrix[id][v[id]], id));
        }
        return tmp.first;
    }
};

// Solution 2
class Solution 
{
public:
    bool check(vector<vector<int>>& matrix, int x, int g)
    {
        int n = matrix.size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int p = upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin();
            cnt += n - p;
        }
        return cnt <= g;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        int ans = l;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(matrix, m, n * n - k))
            {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};
*/
// Solution 3
class Solution 
{
public:
    bool check(vector<vector<int>>& matrix, int x, int g)
    {
        int n = matrix.size(), j = n - 1, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            while (j >= 0 && matrix[i][j] > x) j--;
            cnt += n - 1 - j;
        }
        return cnt <= g;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        int l = matrix[0][0], r = matrix[n - 1][n - 1];
        int ans = l;
        while (l <= r)
        {
            int m = l + r >> 1;
            if (check(matrix, m, n * n - k))
            {
                ans = m;
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> v(3, vector<int>(3));
    v[0][0] = 1; v[0][1] = 5; v[0][2] = 9;
    v[1][0] = 10; v[1][1] = 11; v[1][2] = 13;
    v[2][0] = 12; v[2][1] = 13; v[2][2] = 15;
    cout << Solution().kthSmallest(v, 8) << endl;
}