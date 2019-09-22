class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
    {
        vector<vector<int>> res;
        int minn = INT_MAX;
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; i++) minn = min(minn, arr[i + 1] - arr[i]);
        for (int i = 0; i < arr.size() - 1; i++)
        {
            vector<int> tmp; tmp.push_back(arr[i]); tmp.push_back(arr[i + 1]);
            if (arr[i + 1] - arr[i] == minn) res.push_back(tmp);
        }
        return res;
    }
};