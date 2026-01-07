#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    // Memoization table using a string key for simplicity or a 3D array for max speed
    unordered_map<string, bool> memo;

public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;

        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();

        // Pruning: Check if both strings have the same character frequencies
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        // Try every possible split point
        for (int i = 1; i < n; i++) {
            // Case 1: No swap
            // s1 split: [0, i) and [i, n)
            // s2 split: [0, i) and [i, n)
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
                }

            // Case 2: Swap occurred
            // s1 split: [0, i) and [i, n)
            // s2 split: [n-i, n) and [0, n-i)
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
                }
        }

        return memo[key] = false;
    }
};

// Global Fast I/O
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();