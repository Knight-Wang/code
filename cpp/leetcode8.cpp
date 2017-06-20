#include <iostream>
#include <limits.h>
using namespace std;

class Solution 
{
public:
    int myAtoi(string str) 
    {
        int sign = 1, res = 0, i = 0;
        while (str[i] == ' ') i++;
        if (str[i] == '-' || str[i] == '+') sign = 1 - 2 * (str[i++] == '-');
        while (str[i] >= '0' && str[i] <= '9')
        {
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7'))
                return sign < 0 ? INT_MIN : INT_MAX;
            res = res * 10 + str[i++] - '0';
        }
        return res * sign;
    }
};

int main()
{
	Solution s;
	cout << s.myAtoi("    -2147483648xxx") << endl;
	return 0;
}