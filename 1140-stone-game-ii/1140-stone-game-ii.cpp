class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = sum of piles from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Process from the end towards the beginning
        for (int i = n - 1; i >= 0; i--) {
            for (int M = 1; M <= n; M++) {

                // Can take all remaining piles
                if (i + 2 * M >= n) {
                    dp[i][M] = suffix[i];
                    continue;
                }

                int best = 0;

                // Try taking X piles
                for (int X = 1; X <= 2 * M; X++) {
                    int nextM = max(M, X);

                    // Total remaining stones - Bob's best
                    int alice = suffix[i] - dp[i + X][nextM];

                    best = max(best, alice);
                }

                dp[i][M] = best;
            }
        }

        return dp[0][1];
    }
};