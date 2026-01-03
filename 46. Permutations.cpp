class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int idx, vector<int>& nums) {
        if (idx == nums.size()) {
            res.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            swap(nums[idx], nums[i]);
            backtrack(idx + 1, nums);
            swap(nums[idx], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return res;
    }
};
