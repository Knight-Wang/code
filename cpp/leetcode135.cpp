#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int>& ratings)
    {
        int n = ratings.size();
        if (n <= 1) return n;
        vector<int> v(n, 1);
        for (int i = 1; i < n; i++)
        {
            if (ratings[i] > ratings[i - 1]) v[i] = v[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1]) v[i] = max(v[i + 1] + 1, v[i]);
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};

int main()
{
    int a[] = {1, 2, 3, 3, 3, 2, 1};
    int n = sizeof(a) / sizeof(int);
    vector<int> v(a, a + n);
    cout << Solution().candy(v) << endl;
    return 0;
}