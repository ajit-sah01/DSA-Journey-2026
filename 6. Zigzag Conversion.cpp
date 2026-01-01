#include <string>
using namespace std;

class Solution
{
public:
    string convert(const string &s, int numRows)
    {
        const int n = s.size();
        if (numRows == 1 || numRows >= n)
            return s;

        string result;
        result.reserve(n); // single allocation

        const int cycle = 2 * (numRows - 1);

        for (int row = 0; row < numRows; ++row)
        {
            for (int i = row; i < n; i += cycle)
            {
                result.push_back(s[i]);

                int diag = i + cycle - 2 * row;
                if (row != 0 && row != numRows - 1 && diag < n)
                    result.push_back(s[diag]);
            }
        }

        return result;
    }
};
