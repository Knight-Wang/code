#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
        
        set<vector<int>> s;
        int n = tmp.size();
        
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int left = j + 1, right = n - 1;
                while (left < right)
                {
                    int sum = tmp[i] + tmp[j] + tmp[left] + tmp[right];
                    if (sum < target) left++;
                    else if (sum > target) right--;
                    else
                    {
                        vector<int> t;
                        t.push_back(tmp[i]);
                        t.push_back(tmp[j]);
                        t.push_back(tmp[left]);
                        t.push_back(tmp[right]);
                        s.insert(t);
						int p = left, q = right;
						while (tmp[p] == tmp[left]) left++;
						while (tmp[q] == tmp[right]) right--;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        for (auto it : s)
            ans.push_back(it);
        return ans;
    }
};
int main()
{
	Solution s;
	int x[] = {1, 0, -1, 0, -2, 2};
	vector<int> nums(x, x + 6);
	vector<vector<int>> ans = s.fourSum(nums, 0);
	for (auto it : ans)
	{
		for (auto iter : it)
		{
			cout << iter << " ";
		}
		cout << endl;
	}
	return 0;
}