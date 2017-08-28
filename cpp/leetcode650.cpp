class Solution
{
public:
	int minSteps(int n)
	{
		int sum = 0;
        for (int i = 2; i <= n; i++)
        {
            while (n % i == 0)
            {
                sum += i;
                n /= i;
            }
        }
        return sum;
    }
};