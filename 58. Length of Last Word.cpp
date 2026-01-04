class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.length() - 1;
        int length = 0;

        // Skip trailing spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        // Count characters of the last word
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }

        return length;
    }
};
