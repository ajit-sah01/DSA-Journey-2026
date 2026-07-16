class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
         int n = nums.size();

        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        int leftSum = 0;
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int rightSum = totalSum - leftSum - nums[i];

            int left = nums[i] * i - leftSum;
            int right = rightSum - nums[i] * (n - i - 1);

            ans[i] = left + right;

            leftSum += nums[i];
        }

        return ans;
    }
};