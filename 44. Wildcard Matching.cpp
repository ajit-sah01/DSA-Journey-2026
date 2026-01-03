class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();

        int i = 0, j = 0;
        int starIdx = -1;
        int matchIdx = 0;

        while (i < n) {
            if (j < m && (p[j] == s[i] || p[j] == '?')) {
                i++; j++;
            }
            else if (j < m && p[j] == '*') {
                starIdx = j;
                matchIdx = i;
                j++;
            }
            else if (starIdx != -1) {
                j = starIdx + 1;
                matchIdx++;
                i = matchIdx;
            }
            else {
                return false;
            }
        }

        while (j < m && p[j] == '*') j++;
        return j == m;
    }
};
