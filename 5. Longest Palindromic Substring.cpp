#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(const string &s)
    {
        const int n = s.size();
        if (n < 2)
            return s;

        int start = 0, maxLen = 1;

        for (int i = 0; i < n; ++i)
        {
            // Odd-length palindrome
            expand(s, i, i, start, maxLen);

            // Even-length palindrome
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }

private:
    static void expand(const string &s, int left, int right,
                       int &start, int &maxLen)
    {
        const int n = s.size();

        while (left >= 0 && right < n && s[left] == s[right])
        {
            --left;
            ++right;
        }

        const int len = right - left - 1;
        if (len > maxLen)
        {
            maxLen = len;
            start = left + 1;
        }
    }
};
