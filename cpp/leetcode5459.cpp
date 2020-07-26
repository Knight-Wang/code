class Solution
{
public:
    int minNumberOperations(vector<int>& target)
    {
        if (target.empty()) return 0;
        int n = target.size(), res = target[0];
        for (int i = 1; i < n; i++)
        {
            if (target[i] > target[i - 1]) res += target[i] - target[i - 1]; 
        }
        return res;
    }
};