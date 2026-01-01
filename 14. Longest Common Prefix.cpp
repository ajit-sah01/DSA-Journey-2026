#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); ++i)
        {
            int j = 0;
            // Compare current prefix with next string
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j])
            {
                ++j;
            }
            // Shrink prefix
            prefix = prefix.substr(0, j);
            if (prefix.empty())
                return "";
        }
        return prefix;
    }
};
