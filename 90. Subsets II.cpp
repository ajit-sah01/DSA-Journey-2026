#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void getallSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets)
    {
        if (i == nums.size())
        {
            allSubsets.push_back(ans);
            return;
        }

        // includes
        ans.push_back(nums[i]);
        getallSubsets(nums, ans, i + 1, allSubsets);

        ans.pop_back();

        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1])
        {
            idx++;
        }
        // excliding
        getallSubsets(nums, ans, idx, allSubsets);
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        vector<vector<int>>
            allSubsets;
        vector<int> ans;

        getallSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};
