// Dynamic Median.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <cstdio>
#include <iostream>
#include <functional>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int T, n, d;
	char c;
	cin >> T;
	while (T--)
	{
		priority_queue<int, vector<int>, greater<int>> minq;
		priority_queue<int> maxq;
		cin >> n;
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			if (c == 'I')
			{ 
				cin >> d;
				if (cnt == 0)
				{
					maxq.push(d);
				}
				else if (d > maxq.top())
				{
					if (cnt & 1)
					{
						minq.push(d);
					}
					else
					{
						minq.push(d);
						maxq.push(minq.top());
						minq.pop();
					}
				}
				else
				{
					if (cnt & 1)
					{
						maxq.push(d);
						minq.push(maxq.top());
						maxq.pop();
					}
					else
					{
						maxq.push(d);
					}
				}
				cnt++;
			}
			else if (c == 'Q')
			{
				cout << maxq.top() << endl;
			}
			else
			{
				if (cnt & 1)
				{
					maxq.pop();
				}
				else
				{
					maxq.pop();
					maxq.push(minq.top());
					minq.pop();
				}
				cnt--;
			}
		}
	}
	//system("pause");
	return 0;
}

