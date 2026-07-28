class Solution {
public:
    unordered_set<string> ans;

    void dfs(string &s, int idx, int leftRem, int rightRem,
             int open, string path) {

        if (idx == s.size()) {
            if (leftRem == 0 && rightRem == 0 && open == 0)
                ans.insert(path);
            return;
        }

        char ch = s[idx];

        // Letter
        if (isalpha(ch)) {
            dfs(s, idx + 1, leftRem, rightRem, open, path + ch);
            return;
        }

        // Remove '('
        if (ch == '(' && leftRem > 0)
            dfs(s, idx + 1, leftRem - 1, rightRem, open, path);

        // Remove ')'
        if (ch == ')' && rightRem > 0)
            dfs(s, idx + 1, leftRem, rightRem - 1, open, path);

        // Keep '('
        if (ch == '(')
            dfs(s, idx + 1, leftRem, rightRem, open + 1, path + ch);

        // Keep ')'
        if (ch == ')' && open > 0)
            dfs(s, idx + 1, leftRem, rightRem, open - 1, path + ch);
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0, rightRem = 0;

        for (char ch : s) {
            if (ch == '(') {
                leftRem++;
            } else if (ch == ')') {
                if (leftRem > 0)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        dfs(s, 0, leftRem, rightRem, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};