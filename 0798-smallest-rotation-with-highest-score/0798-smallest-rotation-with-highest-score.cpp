class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int left = (i - nums[i] + 1 + n) % n;
            int right = (i + 1) % n;

            diff[left]--;
            diff[right]++;

            if (left > right)
                diff[0]--;
        }

        int best = 0;
        int score = 0;
        int maxScore = INT_MIN;

        for (int k = 0; k < n; k++) {
            score += diff[k];
            if (score > maxScore) {
                maxScore = score;
                best = k;
            }
        }

        return best;
    }
};