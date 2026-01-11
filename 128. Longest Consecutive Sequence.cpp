class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int num : s) {
            // Check if 'num' is the start of a sequence
            // If num - 1 exists, we skip it because we will process
            // the sequence from its actual beginning later.
            if (s.find(num - 1) == s.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Expand the sequence upwards
                while (s.find(currentNum + 1) != s.end()) {
                    currentNum++;
                    currentStreak++;
                }

                longest = max(longest, currentStreak);
            }

            // Optimization: If the remaining elements in the set are fewer
            // than the 'longest' streak found, we could technically break,
            // but set iteration makes this tricky.
        }

        return longest;
    }
};