class Solution {
public:
    bool isPalindrome(string s) {
        // Fast I/O is mandatory for 0ms
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int l = 0, r = s.length() - 1;

        while (l < r) {
            // Manual range check is faster than isalnum()
            if (!((s[l] >= 'a' && s[l] <= 'z') || (s[l] >= 'A' && s[l] <= 'Z') || (s[l] >= '0' && s[l] <= '9'))) {
                l++;
                continue;
            }
            if (!((s[r] >= 'a' && s[r] <= 'z') || (s[r] >= 'A' && s[r] <= 'Z') || (s[r] >= '0' && s[r] <= '9'))) {
                r--;
                continue;
            }

            // Convert to lowercase manually using bitwise OR
            // Note: 'A' | 32 = 'a'. This works for all letters.
            // We only apply it if it's a letter, not a number.
            char charL = (s[l] >= 'A' && s[l] <= 'Z') ? (s[l] | 32) : s[l];
            char charR = (s[r] >= 'A' && s[r] <= 'Z') ? (s[r] | 32) : s[r];

            if (charL != charR) return false;

            l++;
            r--;
        }
        return true;
    }
};