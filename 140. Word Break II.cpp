#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>

using namespace std;

static const int fastio = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
    unordered_map<string, vector<string>> memo;
    unordered_set<string> dict;

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Clear memo for fresh test cases (needed if object is reused)
        memo.clear();
        dict = unordered_set<string>(wordDict.begin(), wordDict.end());
        return dfs(s);
    }

    vector<string> dfs(string s) {
        // Base case: if we've processed this suffix before, return the result
        if (memo.count(s)) return memo[s];

        // Base case: empty string returns a list containing an empty string
        // to allow for concatenation logic
        if (s.empty()) return {""};

        vector<string> result;

        // Try every possible split point
        for (int i = 1; i <= s.length(); ++i) {
            string prefix = s.substr(0, i);

            if (dict.count(prefix)) {
                // Get all valid sentences for the remaining suffix
                vector<string> suffixWays = dfs(s.substr(i));

                for (string way : suffixWays) {
                    string joined = prefix + (way.empty() ? "" : " ") + way;
                    result.push_back(joined);
                }
            }
        }

        return memo[s] = result;
    }
};