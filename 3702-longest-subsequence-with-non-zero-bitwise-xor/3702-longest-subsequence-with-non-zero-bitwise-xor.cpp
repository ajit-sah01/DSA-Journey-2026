class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        bool hasNonZero = false;

        for (int x : nums) {
            ans ^= x;
            if (x != 0) {
                hasNonZero = true;
            }
        }

        if (ans != 0) {
            return n;
        }

        return hasNonZero ? n - 1 : 0;
    }
};