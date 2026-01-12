#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

using namespace std;

static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        // Use a set for O(1) lookups
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        // dp[i] means s.substr(0, i) can be segmented
        vector<bool> dp(n + 1, false);
        dp[0] = true;

        // Optimization: Find the max word length in the dictionary
        // to avoid checking unnecessarily long substrings
        int maxLen = 0;
        for (const string& word : wordDict) {
            maxLen = max(maxLen, (int)word.length());
        }

        for (int i = 1; i <= n; ++i) {
            // Only check j that could reasonably form a word in the dictionary
            for (int j = i - 1; j >= 0; --j) {
                // If a word is longer than our longest dict word, stop looking back
                if (i - j > maxLen) break;

                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // Found a valid segmentation for this prefix
                }
            }
        }

        return dp[n];
    }
};