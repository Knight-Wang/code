#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int main()
{
	vector<int> v;
	int n, cnt = 1, ans = 0;
	string s;
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
	{
		cin >> s;
		if (s[0] == 'a')
		{
			int tmp;
			scanf("%d", &tmp);
			v.push_back(tmp);
		}
		else
		{
			if (!v.empty()) 
			{
				if (v[v.size() - 1] == cnt) v.pop_back();
				else
				{
					v.clear();
					ans++;
				}
			}
			cnt++;
		}
	}
	printf("%d\n", ans);
	return 0;
}