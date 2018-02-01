#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
	int sum = 0;
	while (x)
	{
		sum += x % 10;
		if (sum > 10) break;
		x /= 10;
	}
	return sum == 10;
}
int main()
{
	int k;
	while (cin >> k)
	{
		int cnt = 0, i = 19;
		for (; ; i++)
		{
			if (check(i)) cnt++;
			if (cnt == k) break;
		}
		cout << i << endl;
	}
	return 0;
}