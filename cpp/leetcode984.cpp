#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string strWithout3a3b(int A, int B)
    {
    	string str = "";
    	if (A == B)
    	{
    		for (int i = 0; i < A; i++) str += "ab";
    	}
    	else
    	{
    		int mx = max(A, B), mn = min(A, B);
  			int s = mx - mn - 1;
  			char p = 'a', q = 'b';
  			if (B > A) swap(p, q);
  			for (int i = 0; i < mn + 1; i++)
  			{
  				str += p;
  				if (i < s) str += p;
  				if (i != mn) str += q;
  			}
    	}
    	return str;
    }
};

int main()
{
	cout << Solution().strWithout3a3b(100, 202) << endl;
	return 0;
}