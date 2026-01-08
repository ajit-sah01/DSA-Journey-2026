class Solution {
public:
    int numTrees(int n) {
        // dp[i] stores the number of unique BSTs with i nodes
        vector<int> dp(n + 1, 0);

        // Base cases:
        // 0 nodes -> 1 empty tree
        // 1 node  -> 1 tree
        dp[0] = 1;
        dp[1] = 1;

        // Build up from 2 nodes to n nodes
        for (int nodes = 2; nodes <= n; ++nodes) {
            for (int root = 1; root <= nodes; ++root) {
                // Number of trees = (trees on left) * (trees on right)
                // Left side has (root - 1) nodes
                // Right side has (nodes - root) nodes
                dp[nodes] += dp[root - 1] * dp[nodes - root];
            }
        }

        return dp[n];
    }
};