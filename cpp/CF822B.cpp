#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	int n, m;
	string s, t;
	cin >> n >> m >> s >> t;
	int minn = INF;
	vector<int> ans;
	for (int i = 0; i <= m - n; i++)
	{
		int cnt = 0;
		vector<int> tmp;
		for (int j = i; j < i + n; j++)
		{
			if (s[j - i] != t[j])
			{
				cnt++;
				tmp.push_back(j - i + 1);
			}
		}
		if (cnt < minn)
		{
			minn = cnt;
			ans = tmp;
		}
	}
	cout << minn << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;
	return 0;
}