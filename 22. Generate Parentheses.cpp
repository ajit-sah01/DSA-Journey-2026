#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        string curr;
        curr.reserve(2 * n); // micro-optimization
        backtrack(n, 0, 0, curr, res);
        return res;
    }

private:
    void backtrack(int n, int open, int close,
                   string &curr,
                   vector<string> &res)
    {
        // If the current string is complete
        if (curr.size() == 2 * n)
        {
            res.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n)
        {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, res);
            curr.pop_back();
        }

        // Add ')' only if it keeps the sequence valid
        if (close < open)
        {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, res);
            curr.pop_back();
        }
    }
};
