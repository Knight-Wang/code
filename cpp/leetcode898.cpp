#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    int subarrayBitwiseORs(vector<int>& A) 
    {
        unordered_set<int> ans, st1, st2;
        for (auto it: A)
        {
            st2 = {it};
            ans.insert(it);
            for (auto it1: st1)
            {
                int tmp = it | it1;
                st2.insert(tmp);
                ans.insert(tmp);
            }
            st1 = st2;
        }
        return ans.size();
    }
};

int main()
{
    int a[] = {1, 2, 4};
    vector<int> v(a, a + 3);
    cout << Solution().subarrayBitwiseORs(v) << endl;
    return 0;
}