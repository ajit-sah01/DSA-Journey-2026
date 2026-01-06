class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to the result (including the empty set)
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);      // Choose the element
            backtrack(nums, i + 1, current, result); // Move to next element
            current.pop_back();              // Backtrack (un-choose)
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        // Pre-allocate memory to avoid reallocations
        result.reserve(1 << nums.size());
        backtrack(nums, 0, current, result);
        return result;
    }
};