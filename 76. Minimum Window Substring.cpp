class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        // Use array instead of map for O(1) access and better cache locality
        int map[128] = {0};
        for (char c : t) map[c]++;

        int left = 0, right = 0;
        int counter = t.size(); // Total characters needed
        int minStart = 0;
        int minLen = INT_MAX;

        while (right < s.size()) {
            // If current char is needed, decrease the total counter
            if (map[s[right]] > 0) {
                counter--;
            }
            // Always decrease the count in our map for the character found
            map[s[right]]--;
            right++;

            // When the window is valid
            while (counter == 0) {
                // Update minimum window result
                if (right - left < minLen) {
                    minLen = right - left;
                    minStart = left;
                }

                // Try to shrink the window from the left
                map[s[left]]++;
                // If the character at left was part of t and now missing
                if (map[s[left]] > 0) {
                    counter++;
                }
                left++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
    }
};