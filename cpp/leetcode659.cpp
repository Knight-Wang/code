#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    bool isPossible(vector<int>& nums) 
    {
        unordered_map<int, int> cnt, end;
        for (auto i : nums) cnt[i]++;
        for (auto i : nums)
        {
            if (cnt[i] == 0) continue;
            else if (end[i - 1] > 0)
            {
                end[i - 1]--;
                end[i]++;
            }
            else if (cnt[i + 1] > 0 && cnt[i + 2] > 0)
            {
                cnt[i + 1]--;
                cnt[i + 2]--;
                end[i + 2]++;
            }
            else return false;
            cnt[i]--;
        }
        return true;
    }
};
int main()
{
	vector<int> x = {1, 2, 3, 3, 4, 4, 5, 5};
	Solution s;
	cout << s.isPossible(x) << endl;
	return 0;
}