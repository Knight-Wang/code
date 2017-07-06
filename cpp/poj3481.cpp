#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int main()
{
	int x;
	map<int, int> m;
	while (scanf("%d", &x), x)
	{
		if (x == 1)
		{
			int k, p;
			scanf("%d %d", &k, &p);
			m[p] = k;
		}
		else if (x == 2)
		{
			if (m.empty()) puts("0");
			else
			{
				printf("%d\n", m.rbegin()->second);
				m.erase(m.find(m.rbegin()->first));
			}
		}
		else
		{
			if (m.empty()) puts("0");
			else
			{
				printf("%d\n", m.begin()->second);
				m.erase(m.begin());
			}
		}
	}
	return 0;
}