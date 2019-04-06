#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countTriplets(vector<int>& A)
    {
        unordered_map<int, int> mp;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tmp = A[i] & A[j];
                if (!mp.count(tmp)) mp[tmp] = 0;
                mp[tmp]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (auto it: mp)
                if ((A[i] & it.first) == 0) ans += it.second;
            
        }
        return ans;
    }
};
int main()
{
    int a[] = {2, 1, 3};
    vector<int> v(begin(a), end(a));
    cout << Solution().countTriplets(v) << endl;
    return 0;
}