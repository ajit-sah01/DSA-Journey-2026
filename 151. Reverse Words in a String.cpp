class Solution {
public:
    string reverseWords(string s) {
        // 1. Reverse the whole string
        reverse(s.begin(), s.end());

        int n = s.length();
        int idx = 0; // The position where we write the "cleaned" characters

        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // If we are starting a new word (and it's not the first word),
                // add a single space separator
                if (idx != 0) s[idx++] = ' ';

                // Find the end of the current word
                int end = start;
                while (end < n && s[end] != ' ') {
                    s[idx++] = s[end++];
                }

                // Reverse the word we just found back to its original order
                // We reverse from (idx - length of word) to idx
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // Move start pointer to the end of this word
                start = end;
            }
        }

        // Resize the string to remove the leftover characters at the end
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};