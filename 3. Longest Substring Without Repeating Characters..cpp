#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(const string &s)
    {
        int lastIndex[128] = {0}; // ASCII character map
        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < (int)s.size(); ++right)
        {
            unsigned char c = s[right];

            // Move left pointer forward only
            left = max(left, lastIndex[c]);
            maxLen = max(maxLen, right - left + 1);

            // Store next valid index
            lastIndex[c] = right + 1;
        }

        return maxLen;
    }
};
