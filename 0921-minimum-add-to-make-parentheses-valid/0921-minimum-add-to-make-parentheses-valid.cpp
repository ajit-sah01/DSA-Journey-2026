class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char ch : s) {
            if (ch == '(') {
                open++;
            } else {
                if (open > 0) {
                    open--;
                } else {
                    ans++;
                }
            }
        }

        return ans + open;
    }
};