#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isMatch(const string &s, const string &p)
    {
        const int n = s.size();
        const int m = p.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // Handle patterns like a*, a*b*, a*b*c*
        for (int j = 2; j <= m; ++j)
        {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    // Zero occurrence
                    dp[i][j] = dp[i][j - 2];

                    // One or more occurrences
                    char prev = p[j - 2];
                    if (prev == s[i - 1] || prev == '.')
                    {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[n][m];
    }
};
