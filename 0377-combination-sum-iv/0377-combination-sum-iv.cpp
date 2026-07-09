class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {

        vector<unsigned int> dp(target + 1, 0);

        dp[0] = 1;

        for (int sum = 1; sum <= target; sum++) {

            for (int num : nums) {

                if (sum >= num)
                    dp[sum] += dp[sum - num];
            }
        }

        return dp[target];
    }
};