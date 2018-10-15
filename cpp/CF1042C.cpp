#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
	int n, x;
	int T = 1;
	while (cin >> n)
	{
		vector<int> v;
		int cnt_neg = 0, max_neg = -INF, max_neg_pos = -1;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			if (x == 0) v.push_back(i);
			else if (x < 0) 
			{ 
				cnt_neg++; 
				if (x > max_neg) { max_neg = x; max_neg_pos = i; }
			}
		}
		if (v.empty())
		{
			if (cnt_neg & 1)
				cout << "2 " << max_neg_pos << endl;
			else max_neg_pos = -1;
			vector<int> tmp;
			for (int i = 1; i <= n; i++)
			{
				if (i == max_neg_pos) continue;
				tmp.push_back(i);
			}
			for (int i = 0; i < tmp.size() - 1; i++)
				cout << "1 " << tmp[i] << " " << tmp[i + 1] << endl;
		}
		else
		{
			for (int i = 0; i < v.size() - 1; i++)
			{
				cout << "1 " << v[i] << " " << v[i + 1] << endl; 
			}
			if (n == v.size()) continue;
			if (cnt_neg & 1) 
			{
				cout << "1 " << v.back() << " " << max_neg_pos << endl;
				if (cnt_neg == 1 && v.size() == n - 1) continue; 
				else cout << "2 " << max_neg_pos << endl;
			}
			else { max_neg_pos = -1; cout << "2 " << v.back() << endl; }
			set<int> st;
			for (auto it: v) st.insert(it);
			vector<int> tmp;
			for (int i = 1; i <= n; i++)
			{
				if (st.count(i) || i == max_neg_pos) continue;
				tmp.push_back(i);
			}
			for (int i = 0; i < tmp.size() - 1; i++)
				cout << "1 " << tmp[i] << " " << tmp[i + 1] << endl;
		}	
	}
	return 0;
}
