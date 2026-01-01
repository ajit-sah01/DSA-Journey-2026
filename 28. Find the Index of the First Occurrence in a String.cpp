class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int n = haystack.size();
        int m = needle.size();

        if (m == 0)
            return 0;

        // Build LPS array
        vector<int> lps(m, 0);
        for (int i = 1, len = 0; i < m;)
        {
            if (needle[i] == needle[len])
            {
                lps[i++] = ++len;
            }
            else if (len > 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i++] = 0;
            }
        }

        // KMP search
        for (int i = 0, j = 0; i < n;)
        {
            if (haystack[i] == needle[j])
            {
                i++;
                j++;
                if (j == m)
                    return i - m;
            }
            else if (j > 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }

        return -1;
    }
};
