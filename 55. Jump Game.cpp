class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;

        for (int i = 0; i < nums.size(); i++) {
            // If current index is unreachable
            if (i > maxReach)
                return false;

            // Update the farthest reachable index
            maxReach = max(maxReach, i + nums[i]);

            // Early exit if we can reach the end
            if (maxReach >= nums.size() - 1)
                return true;
        }

        return true;
    }
};
