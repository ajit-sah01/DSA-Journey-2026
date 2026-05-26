
class Solution
{
public:
    set<vector<int>> s;
    void getAllcombin(vector<int> &arr, int idx, int tar, vector<vector<int>> &ans, vector<int> &combin)
    {
        int n = arr.size();
        if (n == idx || tar < 0)
        {
            return;
        }

        if (tar == 0)
        {
            if (s.find(combin) == s.end())
            {
                ans.push_back(combin);
                s.insert(combin);
            }

            return;
        }

        //// Single Choise
        combin.push_back(arr[idx]);

        getAllcombin(arr, idx + 1, tar - arr[idx], ans, combin);

        //// Mutliple
        getAllcombin(arr, idx, tar - arr[idx], ans, combin);

        combin.pop_back();
        /// excluction
        getAllcombin(arr, idx + 1, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int> &arr, int target)
    {
        vector<vector<int>> ans;
        vector<int> combin;

        getAllcombin(arr, 0, target, ans, combin);
        return ans;
    }
};
