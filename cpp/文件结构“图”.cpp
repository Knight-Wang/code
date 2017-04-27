// 文件结构“图”.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> data;
vector<int> nums;
vector<string> tmp;
int n;
void dfs(int cur, int depth, int num)
{
	if (cur == n)
		return;
	if (data[cur][0] == 'f')
	{
		tmp.push_back(data[cur]);
		dfs(cur + 1, depth, num + 1);
	}
	else if (data[cur][0] == 'd')
	{
		for (int i = 0; i < depth; i++)
			cout << "|     ";
		cout << data[cur] << endl;
		nums.push_back(num);
		dfs(cur + 1, depth + 1, num);
	}
	else
	{
		vector<string> res;
		int l = num - nums[nums.size() - 1];
		for (int i = 0; i < l; i++)
		{
			res.push_back(tmp[tmp.size() - 1]);
			tmp.pop_back();
		}
		nums.pop_back();
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++)
		{
			for (int j = 0; j < depth - 1; j++)
				cout << "|     ";
			cout << res[i] << endl;
		}
		dfs(cur + 1, depth - 1, num - l);
	}
}
int main()
{
	string s;
	cin >> s;
	int t = 0;
	while (s != "#")
	{
		data.clear();
		tmp.clear();
		nums.clear();
		while (s != "*")
		{
			data.push_back(s);
			cin >> s;
		}
		cout << "DATA SET " << ++t << ":" << endl;
		data.push_back("]");
		n = data.size();
		nums.push_back(0);
		cout << "ROOT" << endl;
		dfs(0, 1, 0);
		puts("");
		cin >> s;
	}
	//system("pause");
	return 0;
}

