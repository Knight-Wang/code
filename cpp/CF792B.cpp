// CF792B.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int b[105];
int n, k;
vector<int> a;
int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> b[i];
	}
	int leader = 0;
	for (int i = 0; i < n; i++)
		a.push_back(i + 1);
	for (int i = 0; i < k; i++)
	{
		int out = (leader + b[i]) % a.size();
		int tmp = *(a.begin() + out);
		cout << tmp << " ";
		a.erase(a.begin() + out);
		leader = out % a.size();
	}
	puts("");
	//system("pause");
	return 0;
}

