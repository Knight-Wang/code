#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

class Solution 
{
public:
    vector<vector<int> > permute(vector<int>& nums) 
	{
		vector<vector<int> > res;
		int n = nums.size();
		sort(nums.begin(), nums.end());
		do
		{
			vector<int> tmp;
			for (int i = 0; i < n; i++)
			{
				tmp.push_back(nums[i]);
			}
			res.push_back(tmp);
		} while(next_permutation(nums.begin(), nums.end()));
		return res;
    }
};

int main()
{
	Solution s;
	int tmp[] = {3, 2, 1};
	vector<int> x(tmp, tmp + 3);
	vector<vector<int> > res = s.permute(x);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		puts("");
	}
	return 0;
}