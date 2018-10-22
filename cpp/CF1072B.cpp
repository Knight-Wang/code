#include <iostream>
#include <vector>

using namespace std;
int a[200005], b[200005];
int get(int t, int a, int b)
{
	int ans = 0, cnt = 0;
	while (t || a || b)
	{
		int x = t & 1, y = a & 1, z = b & 1;
		if (x == 0 && y == 1 && z == 0) ans |= 1 << cnt;
		else if (x == 1 && y == 1 && z == 1) ans |= 1 << cnt;
		else if (x == 0 && y == 1 && z == 1) return -1;
		else if (x == 0 && y == 0 && z == 1) return -1;
		else if (x == 1 && y == 0 && z == 0) return -1;
		else if (x == 1 && y == 0 && z == 1) return -1;
		t >>= 1;
		a >>= 1;
		b >>= 1;
		cnt++;
	}
	return ans;
}
int main()
{
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n - 1; i++) cin >> a[i];
		for (int i = 0; i < n - 1; i++) cin >> b[i];
		bool ok = false;
		for (int k = 0; k < 4; k++)
		{
			if (ok) break;
			vector<int> v;
			v.push_back(k);
			bool flg = true;
			for (int i = 0; i < n - 1; i++)
			{
				int tmp = get(v.back(), a[i], b[i]);
				if (tmp == -1) { flg = false; break; } 
				v.push_back(tmp);
			}
			if (flg)
			{
				cout << "YES" << endl;
				for (auto it: v) cout << it << " ";
				cout << endl;
				ok = true;
			}
		}
		if (!ok) cout << "NO" << endl;
	}
	return 0;
}
