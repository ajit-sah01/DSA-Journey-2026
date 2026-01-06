class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // Ensure m is the smaller string length to minimize space to O(min(n, m))
        if (n < m) return minDistance(word2, word1);

        // Use a fixed-size array on the stack for speed (max constraint is 500)
        int dp[501];

        // Base case: transforming word1[0...0] to empty word2
        for (int j = 0; j <= m; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            int pre = dp[0]; // Stores the "top-left" value (dp[i-1][j-1])
            dp[0] = i;      // Base case for current row

            for (int j = 1; j <= m; j++) {
                int temp = dp[j]; // Store current dp[j] before it's overwritten

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = pre;
                } else {
                    // Min of: Top (dp[j]), Left (dp[j-1]), and Top-Left (pre)
                    int mn = dp[j];
                    if (dp[j - 1] < mn) mn = dp[j - 1];
                    if (pre < mn) mn = pre;
                    dp[j] = 1 + mn;
                }
                pre = temp; // Update "top-left" for the next iteration
            }
        }

        return dp[m];
    }
};