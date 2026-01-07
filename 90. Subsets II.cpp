#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort to bring duplicates together for easy pruning
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        // Pre-allocate for the worst-case (2^n) to prevent reallocations
        result.reserve(1 << nums.size());

        vector<int> current;
        current.reserve(nums.size());

        backtrack(nums, 0, current, result);
        return result;
    }

private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        // Add the current subset to result (makes a copy)
        result.push_back(current);

        for (int i = start; i < nums.size(); ++i) {
            // Pruning: skip duplicates at the same recursion level
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            current.push_back(nums[i]);
            backtrack(nums, i + 1, current, result);
            current.pop_back(); // Backtrack
        }
    }
};

// Global Fast I/O
static const auto fast_io = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();