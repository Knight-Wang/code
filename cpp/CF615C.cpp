#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXN = 2105;
int neXt[MAXN];

void getNext(string s)
{
	int n = s.length();
	neXt[0] = -1;
	int k = -1, j = 0;
	while (j < n)
	{
		if (k == -1 || s[j] == s[k])
		{
			j++; k++;
			if (s[j] != s[k]) neXt[j] = k;
			else neXt[j] = neXt[k];
		}
		else
		{
			k = neXt[k];
		}
	}
}

int kmp(string s, string p)
{
	int i = 0, j = 0;
	int m = s.length(), n = p.length();
	while (i < m && j < n)
	{
		if (j == -1 || s[i] == p[j]) i++, j++;
		else j = neXt[j];
	}
	if (j == n) return i - j;
	return -1;
}

bool solve(string x, string y, vector<pair<int, int>> & ans)
{
	string z(x);
	reverse(z.begin(), z.end());
	int m = x.length();
	int n = y.length();
	int start = 0;
	while (start < n)
	{
		int l = 1, r = n - start, res = 0, pos = -1;
		bool flg = true;
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			string tmp = y.substr(start, mid);
			getNext(tmp);
			int p = kmp(x, tmp);
			if (p != -1)
			{
				res = mid; pos = p; flg = true; l = mid + 1;
			}
			else if ((p = kmp(z, tmp)) != -1)
			{
				res = mid; pos = p; flg = false; l = mid + 1;
			}
			else r = mid - 1;
		}
		if (!res) return false;
		if (flg) ans.push_back(pair<int, int>(pos + 1, pos + res));
		else ans.push_back(pair<int, int>(m - pos, m - pos - res + 1));
		start += res;
	}
	return true;
}
	
int main()
{
	string x, y;
	cin >> x >> y;
	vector<pair<int, int>> res;
	if (solve(x, y, res))
	{
		cout << res.size() << endl;
		for (int i = 0; i < res.size(); i++)
			cout << res[i].first << " " << res[i].second << endl;
	}
	else
	{
		puts("-1");
	}
	return 0;
}