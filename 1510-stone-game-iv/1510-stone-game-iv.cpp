class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        dp[0] = false;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;

                // If opponent is in a losing state,
                // current player wins.
                if (!dp[i - square]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};