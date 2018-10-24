#include <iostream>
#include <map>
#include <vector>
using namespace std;
class Solution 
{
public:
    string fractionToDecimal(int numerator, int denominator) 
    {
        long long a = numerator, b = denominator;
        string ans = "";
        if (a * b < 0) ans += '-';
        a = abs(a); b = abs(b);
        ans += to_string(a / b);
        a %= b;
        if (!a) return ans;
        ans += '.';
		a *= 10;
		vector<long long> v;
		map<pair<long long, long long>, int> mp;
		long long rem = a % b, q = a / b;
		while (rem && !mp.count(make_pair(rem, q)))
		{
			v.push_back(q);
			mp[make_pair(rem, q)] = v.size() - 1;
			rem *= 10;
			q = rem / b;
			rem %= b;
		}
		if (rem == 0) 
		{
			v.push_back(q);
			for (auto it: v) ans += to_string(it);
		}
		else
		{
			int start = mp[make_pair(rem, q)];
			for (int i = 0; i < start; i++) ans += to_string(v[i]);
			ans += '(';
			for (int i = start; i < v.size(); i++) ans += to_string(v[i]);
			ans += ')';
		}
        return ans;
    }
};
int main()
{
	cout << Solution().fractionToDecimal(-1, -2147483648) << endl;
	return 0;
}
