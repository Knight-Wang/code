// LEETCODE 45.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution 
{
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int jump(vector<int>& nums)
	{
		int n = nums.size();
		if (n < 2)
			return 0;
		int depth = 0, curMax = 0, nextMax = 0;
		while (curMax >= depth)
		{
			for (int i = depth; i <= curMax; i++)
			{
				nextMax = max(nextMax, nums[i] + i);
				if (nextMax >= n - 1)
					return depth + 1;
			}
			depth++;
			curMax = nextMax;
		}
		return -1;
	}
};

int main()
{
	Solution s;
	vector<int> v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(1);
	v.push_back(1);
	v.push_back(4);
	cout << s.jump(v) << endl;
	system("pause");
	return 0;
}

