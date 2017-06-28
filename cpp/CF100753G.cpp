#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	//freopen("c:\\users\\wangyiming\\desktop\\in.txt", "r", stdin);
	int n, tmp, last = 1;
	cin >> n;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp < last)
		{
			flag = false;
			break;
		}
		last = tmp;
	}
	cout << (flag ? "yes" : "no") << endl;
	return 0;
}