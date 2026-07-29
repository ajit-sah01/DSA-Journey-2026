class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<long long> dp(k + 1, 0);

        int moves = 0;

        while (dp[k] < n) {
            moves++;

            for (int e = k; e >= 1; e--) {
                dp[e] = dp[e] + dp[e - 1] + 1;
            }
        }

        return moves;
    }
};