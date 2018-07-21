// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution 
{
public:
    int rand10() 
    {
        int ans = 40;
        while (ans >= 40)
        {
            int x = rand7(), y = rand7();
            ans = (x - 1) * 7 + y - 1;
        }
        return ans % 10 + 1;
    }
};