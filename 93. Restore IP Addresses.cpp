#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string currentIP;
        backtrack(s, 0, 0, currentIP, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, int step, string currentIP, vector<string>& result) {
        // Base case: If we have 4 segments
        if (step == 4) {
            // If we've also used all characters in the string, it's a valid IP
            if (start == s.length()) {
                result.push_back(currentIP.substr(0, currentIP.length() - 1)); // Remove trailing dot
            }
            return;
        }

        // Optimization: If remaining characters are too many or too few for remaining segments
        int remainingChars = s.length() - start;
        int remainingSteps = 4 - step;
        if (remainingChars < remainingSteps || remainingChars > remainingSteps * 3) {
            return;
        }

        for (int len = 1; len <= 3 && start + len <= s.length(); ++len) {
            string part = s.substr(start, len);

            // Check for leading zeros and value range
            if ((part[0] == '0' && len > 1) || stoi(part) > 255) {
                break;
            }

            backtrack(s, start + len, step + 1, currentIP + part + ".", result);
        }
    }
};