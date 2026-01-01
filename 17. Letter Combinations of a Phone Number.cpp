#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        if (digits.empty())
            return res;

        static const string map[10] = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string curr;
        curr.reserve(digits.size()); // micro-optimization

        backtrack(digits, 0, map, curr, res);
        return res;
    }

private:
    void backtrack(const string &digits, int idx,
                   const string map[],
                   string &curr,
                   vector<string> &res)
    {
        if (idx == digits.size())
        {
            res.push_back(curr);
            return;
        }

        const string &letters = map[digits[idx] - '0'];
        for (char c : letters)
        {
            curr.push_back(c);
            backtrack(digits, idx + 1, map, curr, res);
            curr.pop_back(); // backtrack
        }
    }
};
