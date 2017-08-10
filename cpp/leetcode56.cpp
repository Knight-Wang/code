#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval 
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution 
{
public:
    vector<Interval> merge(vector<Interval>& intervals) 
    {
		if (intervals.empty()) return vector<Interval>{};
		vector<Interval> tmp(intervals.begin(), intervals.end());
		sort(tmp.begin(), tmp.end(), [](Interval & a, Interval & b){ return a.start < b.start; });
		vector<Interval> ret;
		ret.push_back(tmp[0]);
		for (int i = 1; i < tmp.size(); i++)
		{
			if (tmp[i].start > ret.back().end) ret.push_back(tmp[i]);
			else ret.back().end = max(ret.back().end, tmp[i].end);
		}
		return ret;
    }
};

int main()
{
	vector<Interval> test;
	test.push_back(Interval(2, 3));
	test.push_back(Interval(4, 5));
	test.push_back(Interval(6, 7));
	test.push_back(Interval(8, 9));
	test.push_back(Interval(1, 10));
	Solution s;
	vector<Interval> ans = s.merge(test);
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].start << " " << ans[i].end << endl;
	return 0;
}