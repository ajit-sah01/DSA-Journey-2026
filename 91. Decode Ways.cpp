#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        // prev2 represents dp[i-2], prev1 represents dp[i-1]
        int prev2 = 1;
        int prev1 = 1;

        for (int i = 2; i <= n; ++i) {
            int current = 0;

            // Check if single digit s[i-1] is valid (1-9)
            if (s[i-1] != '0') {
                current += prev1;
            }

            // Check if two digits s[i-2...i-1] are valid (10-26)
            int twoDigit = stoi(s.substr(i-2, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                current += prev2;
            }

            // Update variables for next iteration
            prev2 = prev1;
            prev1 = current;

            // Early exit: if no ways to decode up to this point
            if (prev1 == 0) return 0;
        }

        return prev1;
    }
};