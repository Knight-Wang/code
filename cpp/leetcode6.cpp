// leetcode6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

class Solution 
{
public:
	string convert(string s, int numRows) 
	{
		if (numRows == 1)
			return s;
		int n = s.length();
		string res = "";
		for (int i = 0; i < numRows; i++)
		{
			for (int j = i; j < n; j += 2 * numRows - 2)
			{
				res += s[j];
				if (i != 0 && i != numRows - 1 && j + (numRows - 1 - i) * 2 < n)
					res += s[j + (numRows - 1 - i) * 2];
			}
		}
		return res;
	}
};
int main()
{
	Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
	cout << s.convert("ABCD", 3) << endl;
	system("pause");
	return 0;
}

