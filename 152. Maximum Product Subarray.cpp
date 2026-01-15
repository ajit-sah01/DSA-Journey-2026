class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty()) return 0;

        int res = nums[0];
        int curMax = nums[0];
        int curMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int val = nums[i];

            // If the current value is negative, the max and min swap
            // because multiplying by a negative flips the signs.
            if (val < 0) {
                swap(curMax, curMin);
            }

            // At each step, we decide:
            // Do we start a new subarray at 'val', or extend the existing one?
            curMax = max(val, curMax * val);
            curMin = min(val, curMin * val);

            // Update the global result
            res = max(res, curMax);
        }

        return res;
    }
};