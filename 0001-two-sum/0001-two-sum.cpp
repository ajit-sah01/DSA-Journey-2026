class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Brute Force Approach
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     for (int j = i + 1; j < n; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             return {i, j};
        //         }
        //     }
        // }
        // return {};

        // Optimized Approach - Unordered Map
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {

            int need = target - nums[i];

            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};