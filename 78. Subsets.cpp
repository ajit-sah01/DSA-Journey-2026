

class Solution
{
public:
    void GetallSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
    {
        if (i == nums.size())
        {
            allSubsets.push_back({ans});
            return;
        }
        // includes
        ans.push_back(nums[i]);
        GetallSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();
        // exclude
        GetallSubsets(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> allSubsets;
        vector<int> ans;
        GetallSubsets(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};
