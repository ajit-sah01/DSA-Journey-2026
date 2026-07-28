class Solution {
public:
    vector<string> ans;
    unordered_set<string> vis;

    void dfs(string &s, int idx, int leftRem, int rightRem,
             int open, string &path) {

        if (idx == s.size()) {
            if (leftRem == 0 && rightRem == 0 && open == 0) {
                if (vis.insert(path).second)
                    ans.push_back(path);
            }
            return;
        }

        char ch = s[idx];

        if (isalpha(ch)) {
            path.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, open, path);
            path.pop_back();
            return;
        }

        // Remove current parenthesis
        if (ch == '(' && leftRem > 0)
            dfs(s, idx + 1, leftRem - 1, rightRem, open, path);

        if (ch == ')' && rightRem > 0)
            dfs(s, idx + 1, leftRem, rightRem - 1, open, path);

        // Keep '('
        if (ch == '(') {
            path.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, open + 1, path);
            path.pop_back();
        }

        // Keep ')'
        if (ch == ')' && open > 0) {
            path.push_back(ch);
            dfs(s, idx + 1, leftRem, rightRem, open - 1, path);
            path.pop_back();
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int leftRem = 0, rightRem = 0;

        for (char c : s) {
            if (c == '(')
                leftRem++;
            else if (c == ')') {
                if (leftRem)
                    leftRem--;
                else
                    rightRem++;
            }
        }

        string path;
        dfs(s, 0, leftRem, rightRem, 0, path);

        return ans;
    }
};