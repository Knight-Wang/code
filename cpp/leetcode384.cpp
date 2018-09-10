#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
	vector<int> a, b;
    Solution(vector<int> nums) 
	{
		for (auto it: nums) 
		{
			a.push_back(it);
			b.push_back(it);
		}
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
	{
        return a;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
	{
		vector<int> ans;
        int n = b.size();
		int cnt = n;
		for (int i = 0; i < n; i++)
		{
			int id = rand() % cnt;
			ans.push_back(b[id]);
			swap(b[id], b[cnt - 1]);
			cnt--;
		}
		return ans;
    }
};

int main()
{
	int x[] = {1, 2, 3};
	vector<int> nums(x, x + 3);
	Solution s(nums);
	vector<int> res = s.shuffle();
	for (auto it: res) cout << it << " ";
	cout << endl;
	return 0;
}