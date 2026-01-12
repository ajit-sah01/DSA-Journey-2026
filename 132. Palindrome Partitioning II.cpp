#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        if (n <= 1) return 0;

        // Step 1: Precompute palindrome table
        // isPal[i][j] is true if s[i...j] is a palindrome
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int right = 0; right < n; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 2 || isPal[left + 1][right - 1])) {
                    isPal[left][right] = true;
                }
            }
        }

        // Step 2: DP for min cuts
        // dp[i] = min cuts for substring s[0...i]
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0; // No cuts needed if the whole prefix is a palindrome
            } else {
                int min_val = i; // Max cuts possible is i (cutting every char)
                for (int j = 1; j <= i; j++) {
                    if (isPal[j][i]) {
                        min_val = min(min_val, dp[j - 1] + 1);
                    }
                }
                dp[i] = min_val;
            }
        }

        return dp[n - 1];
    }
};