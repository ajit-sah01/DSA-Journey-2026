static const int speedup = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        // If s is shorter than t, no subsequence is possible
        if (m < n) return 0;

        // Use unsigned long long to prevent overflow during intermediate steps
        // dp[j] stores the number of ways to form t[0...j-1]
        vector<unsigned long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= m; i++) {
            // Optimization: Only iterate as far as the current s prefix allows
            // and stop if there aren't enough characters left in s to finish t.
            int start = min(i, n);
            for (int j = start; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return (int)dp[n];
    }
};