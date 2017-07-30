#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1000005;
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
			neXt[j] = k;
		}
		else
		{
			k = neXt[k];
		}
	}
}

bool kmp(string s, string p)
{
	int i = 0, j = 0;
	int m = s.length(), n = p.length();
	while (i < m && j < n)
	{
		if (j == -1 || s[i] == p[j]) i++, j++;
		else j = neXt[j];
	}
	if (j == n) return true;
	return false;
}

int main()
{
	string str;
	cin >> str;
	str += ' ';
	int n = str.length();
	getNext(str);
	int tmp = neXt[n - 1];
	bool flg = false;
	while (tmp)
	{
		if (kmp(str.substr(1, n - 3), str.substr(0, tmp)))
		{
			cout << str.substr(0, tmp) << endl;
			flg = true;
			break;
		}
		tmp = neXt[tmp];
	}
	if (!flg) cout << "Just a legend" << endl;
	return 0;
}