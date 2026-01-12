class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.length();
        // 1. Bitset or vector<vector<bool>> for DP.
        // vector<deque> or vector<vector<char>> is sometimes faster due to bit packing.
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int right = 0; right < n; right++) {
            for (int left = 0; left <= right; left++) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1])) {
                    dp[left][right] = true;
                }
            }
        }

        vector<vector<string>> result;
        vector<string> currentPath;
        // Optimization: Reserve space to avoid multiple reallocations
        currentPath.reserve(n);

        dfs(s, 0, dp, currentPath, result);
        return result;
    }

private:
    void dfs(const string& s, int start, const vector<vector<bool>>& dp,
             vector<string>& currentPath, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(currentPath);
            return;
        }

        for (int end = start; end < s.length(); end++) {
            if (dp[start][end]) {
                // We still use substr here, but only for valid palindromes.
                // To go even faster, some use string_view (C++17),
                // but LeetCode's result type is vector<string>.
                currentPath.push_back(s.substr(start, end - start + 1));
                dfs(s, end + 1, dp, currentPath, result);
                currentPath.pop_back(); // Backtrack
            }
        }
    }
};