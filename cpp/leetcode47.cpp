class Solution 
{
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) 
	{
		set<vector<int>> res;
        vector<int> tmp(nums.begin(), nums.end());
        sort(tmp.begin(), tmp.end());
		int n = tmp.size();
		do
		{
			vector<int> buf(tmp.begin(), tmp.end());
			res.insert(buf);
		} while(next_permutation(tmp.begin(), tmp.end()));
		vector<vector<int>> ret;
        for (auto it : res)
        {
            ret.push_back(it);
        }
        return ret;
    }
};