#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

class Solution 
{
public:
    vector<int> buf;
    vector<vector<int>> ret;
    void dfs(int cur, int sum, int n, vector<int>& cand)
    {
        if (sum <= 0 || cur == n)
        {
            if (sum == 0)
            {
                ret.push_back(vector<int>());
                for (int i = 0; i < buf.size(); i++)
                {
                    ret[ret.size() - 1].push_back(buf[i]);
                }
            }
            return;
        }
        buf.push_back(cand[cur]);
		dfs(cur, sum - cand[cur], n, cand);
		buf.pop_back();
        dfs(cur + 1, sum, n, cand);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<int> tmp(candidates.begin(), candidates.end());
        sort(tmp.begin(), tmp.end());
        int n = upper_bound(tmp.begin(), tmp.end(), target) - tmp.begin();
        dfs(0, target, n, tmp);
        return ret; 
    }
};
int main()
{
	int a[] = {2, 3, 6, 7};
	vector<int> test(a, a + 4);
	Solution s;
	vector<vector<int>> res = s.combinationSum(test, 7);
	for (int i = 0; i < res.size(); i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}