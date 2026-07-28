class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);

        for (char c : s) cnt[c - 'a']++;

        string first = "";
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            first.append(cnt[i] / 2, char('a' + i));
            if (cnt[i] % 2) mid = char('a' + i);
        }

        string second = first;
        reverse(second.begin(), second.end());

        if (mid)
            return first + string(1, mid) + second;

        return first + second;
    }
};