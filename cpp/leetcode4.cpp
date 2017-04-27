// leetcode4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

class Solution 
{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size(); int n = nums2.size();
		if(m > n)
		{
			vector<int> tmp = nums1;
			nums1 = nums2;
			nums2 = tmp; 
			m = nums1.size();
			n = nums2.size();
		}
		int left = 0;
		int right = m;
		int i, j;
		double maxL, minR, ans;
		while (left <= right)
		{
			i = (left + right) >> 1;
			j = (m + n + 1) / 2 - i;
			if ((i == 0 || j == n || nums1[i - 1] <= nums2[j]) && (j == 0 || i == m || nums2[j - 1] <= nums1[i]))
			{
				if (i == 0)
					maxL = nums2[j - 1];
				else if (j == 0)
					maxL = nums1[i - 1];
				else
					maxL = max(nums1[i - 1], nums2[j - 1]);
				if ((m + n) & 1)
					ans = maxL;
				else
				{
					if (i == m)
						minR = nums2[j];
					else if (j == n)
						minR = nums1[i];
					else
						minR = min(nums1[i], nums2[j]);
					ans = (maxL + minR) / 2.0;
				}
				break;
			}
			else if (i > 0 && nums1[i - 1] > nums2[j])
			{
				right = i - 1;
			}
			else 
			{
				left = i + 1;
			}
		}
		return ans;
	}
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int min(int a, int b)
	{
		return a < b ? a : b;
	}
};
int main()
{
	vector<int> a = {1, 2};
	vector<int> b;
	Solution s;
	cout << s.findMedianSortedArrays(a, b) << endl;
	system("pause");
	return 0;
}

