#include <bits/stdc++.h>
using namespace std;

class Solution 
{
public:
    inline bool cmp(pair<int, string> a, pair<int, string> b)
    {
        if (a.first > b.first) return true;
        if (a.first == b.first && a.second < b.second) return true;
        return false;
    }
	struct cmp1
	{
		bool operator()(const pair<int, string>& a, const pair<int, string>& b) const
		{
			if (a.first > b.first) return true;
			if (a.first == b.first && a.second < b.second) return true;
			return false;
		}
	};
	vector<string> topKFrequent(vector<string>& words, int k) 
    {
        unordered_map<string, int> mp;
        for (auto it : words) mp[it]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp1> q;
        int cnt = 0;
        for (auto it : mp)
        {
            pair<int, string> tmp(it.second, it.first);				
            if (cnt < k) 
			{
				q.push(tmp); 				
			}
			else if (cmp(tmp, q.top())) 
			{ 
				q.push(tmp);				
				q.pop(); 
			}			
            cnt++;
        }
        vector<string> ret;
        while (!q.empty()) 
		{
			ret.push_back(q.top().second); q.pop(); 
		}		
        reverse(ret.begin(), ret.end());
		return ret;                     
    }
};
int main()
{
	vector<string> v = {"i", "love", "leetcode", "i", "love", "coding"};
	vector<string> ret = Solution().topKFrequent(v, 2);
	for (auto it : ret)
	{
		cout << it << " ";
	}
	cout << endl;
	return 0;
}
