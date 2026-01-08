#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        // If the total length doesn't match, it's impossible
        if (n + m != s3.length()) return false;

        // dp[j] represents whether s3[0...i+j-1] can be formed
        // using s1[0...i-1] and s2[0...j-1]
        vector<bool> dp(m + 1, false);

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[j] = true; // Base case
                } else if (i == 0) {
                    // Only using characters from s2
                    dp[j] = dp[j - 1] && (s2[j - 1] == s3[i + j - 1]);
                } else if (j == 0) {
                    // Only using characters from s1
                    dp[j] = dp[j] && (s1[i - 1] == s3[i + j - 1]);
                } else {
                    // Can we reach this state from either the top (s1) or the left (s2)?
                    dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                            (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
                }
            }
        }

        return dp[m];
    }
};