#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(const string &s, const string &p)
    {
        int n = s.size(); // length of input string
        int m = p.size(); // length of pattern

        // dp[i][j] = true if s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base case: empty string matches empty pattern
        dp[0][0] = true;

        // 🔹 Handle patterns like a*, a*b*, a*b*c*
        // These can match an empty string
        for (int j = 2; j <= m; ++j)
        {
            if (p[j - 1] == '*')
            {
                dp[0][j] = dp[0][j - 2]; // ignore "x*"
            }
        }

        // 🔹 Fill DP table
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                // ✅ Case 1: Direct match or '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }

                // ✅ Case 2: '*'
                else if (p[j - 1] == '*')
                {
                    // 🔸 Option 1: Treat '*' as zero occurrence
                    dp[i][j] = dp[i][j - 2];

                    // 🔸 Option 2: One or more occurrences
                    char prev = p[j - 2]; // character before '*'

                    if (prev == s[i - 1] || prev == '.')
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        // Final result: full string vs full pattern
        return dp[n][m];
    }
};
